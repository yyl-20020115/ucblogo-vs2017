#ifdef _WINDOWS
#include <windows.h>

unsigned int GetWd(unsigned int length, char* p)
{
	memset(p, 0, length);
	int r = GetModuleFileNameA(0, p, length);
	if (r > 0) {

		char* pb =strrchr(p, '\\');
		if (pb != 0) {
			*(pb + 1) = '\0';
		}
		else {
			*p = '.';
			*(p + 1) = '\\';
			*(p + 2) = '\0';
			r = 2;
		}
	}
	return r;
}

#endif