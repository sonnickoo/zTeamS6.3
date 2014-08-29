#pragma once
// -------------------------------------------------------------------------------

#include "../Lua/include/lua.hpp"
#include "../common/winutil.h"
#include "Event.h"
#include "BuffEffectSlot.h"
// -------------------------------------------------------------------------------

#define GetName(a)		#a
// -------------------------------------------------------------------------------

#define MAX_OBJ_VARIBLES	21
#define MAX_NPC_VARIBLES	6
// -------------------------------------------------------------------------------

static struct ObjMapInt
{
	const char *	Name;
	int				Varible;
};
// -------------------------------------------------------------------------------

class LuaNPC
{
public:
	LuaNPC();
	virtual ~LuaNPC();
	// ----
	bool			Run(LPOBJ lpObj, LPOBJ lpNpc);
	// ----
	void			RegisterData(lua_State * Lua, const luaL_Reg * Table, char * TableName, char * DataName, size_t Size);
	// ----
	void			InsertObjMapData(LPOBJ lpObj)
	{
		this->ObjMap[0].Name	= "aIndex";
		this->ObjMap[0].Varible	= lpObj->m_Index;
		// ----
		this->ObjMap[1].Name	= "Level";
		this->ObjMap[1].Varible	= lpObj->Level;
		// ----
		this->ObjMap[2].Name	= "m_nMasterLevel";
		this->ObjMap[2].Varible	= lpObj->m_nMasterLevel;
		// ----
		this->ObjMap[3].Name	= "Class";
		this->ObjMap[3].Varible	= lpObj->Class;
		// ----
		this->ObjMap[4].Name	= "Strength";
		this->ObjMap[4].Varible	= lpObj->Strength;
		// ----
		this->ObjMap[5].Name	= "Dexterity";
		this->ObjMap[5].Varible	= lpObj->Dexterity;
		// ----
		this->ObjMap[6].Name	= "Vitality";
		this->ObjMap[6].Varible	= lpObj->Vitality;
		// ----
		this->ObjMap[7].Name	= "Energy";
		this->ObjMap[7].Varible	= lpObj->Energy;
		// ----
		this->ObjMap[8].Name	= "Leadership";
		this->ObjMap[8].Varible	= lpObj->Leadership;
		// ----
		this->ObjMap[9].Name	= "Money";
		this->ObjMap[9].Varible	= lpObj->Money;
		// ----
		this->ObjMap[10].Name	= "MapNumber";
		this->ObjMap[10].Varible= lpObj->MapNumber;
		// ----
		this->ObjMap[11].Name	= "X";
		this->ObjMap[11].Varible= lpObj->X;
		// ----
		this->ObjMap[12].Name	= "Y";
		this->ObjMap[12].Varible= lpObj->Y;
		// ----
		this->ObjMap[13].Name	= "Authority";
		this->ObjMap[13].Varible= lpObj->Authority;
		// ----
		this->ObjMap[14].Name	= "Reset";
		this->ObjMap[14].Varible= lpObj->Reset;
		// ----
		this->ObjMap[15].Name	= "m_IfStateUse";
		this->ObjMap[15].Varible= lpObj->m_IfState.use;
		// ----
		this->ObjMap[16].Name	= "m_IfStateState";
		this->ObjMap[16].Varible= lpObj->m_IfState.state;
		// ----
		this->ObjMap[17].Name	= "m_IfStateType";
		this->ObjMap[17].Varible= lpObj->m_IfState.type;
		// ----
		this->ObjMap[18].Name	= "GuildNumber";
		this->ObjMap[18].Varible= lpObj->GuildNumber;
		// ----
		this->ObjMap[19].Name	= "PartyNumber";
		this->ObjMap[19].Varible= lpObj->PartyNumber;
		// ----
		this->ObjMap[20].Name	= "m_PK_Level";
		this->ObjMap[20].Varible= lpObj->m_PK_Level;
	};
	// ----
	void			InsertNpcMapData(LPOBJ lpNpc)
	{
		this->NpcMap[0].Name	= "aIndex";
		this->NpcMap[0].Varible	= lpNpc->m_Index;
		// ----
		this->NpcMap[1].Name	= "Class";
		this->NpcMap[1].Varible	= lpNpc->Class;
		// ----
		this->NpcMap[2].Name	= "MapNumber";
		this->NpcMap[2].Varible	= lpNpc->MapNumber;
		// ----
		this->NpcMap[3].Name	= "X";
		this->NpcMap[3].Varible	= lpNpc->X;
		// ----
		this->NpcMap[4].Name	= "Y";
		this->NpcMap[4].Varible	= lpNpc->Y;
		// ----
		this->NpcMap[5].Name	= "TargetNumber";
		this->NpcMap[5].Varible	= lpNpc->TargetNumber;
	};
	// ----
	static BOOL		GetVaribleObj(lua_State * Lua);
	static BOOL		SetVaribleObj(lua_State * Lua);
	static BOOL		GetVaribleNpc(lua_State * Lua);
	static BOOL		SetVaribleNpc(lua_State * Lua);
	// ----
public:
	ObjMapInt		ObjMap[MAX_OBJ_VARIBLES];
	ObjMapInt		NpcMap[MAX_NPC_VARIBLES];
	// ----
}; extern LuaNPC gLuaNPC;
// ------------------------------------------------------------------------------

