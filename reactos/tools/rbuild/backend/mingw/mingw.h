#ifndef MINGW_H
#define MINGW_H

#include "../backend.h"
#include "modulehandler.h"

class MingwBackend : public Backend
{
public:
	MingwBackend ( Project& project );
	virtual void Process ();
private:
	void ProcessModule ( Module& module );
	void CreateMakefile ();
	void CloseMakefile ();
	void GenerateHeader ();
	void
	MingwBackend::GenerateGlobalCFlagsAndProperties (
		const char* op,
		const std::vector<Property*>& properties,
		const std::vector<Include*>& includes,
		const std::vector<Define*>& defines,
		const std::vector<If*>& ifs );
	void GenerateGlobalVariables ();
	void GenerateAllTarget ();
	FILE* fMakefile;
};

std::string FixupTargetFilename ( const std::string& targetFilename );

#endif /* MINGW_H */
