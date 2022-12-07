#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
char a[11111];
int b[255];

int main() {
	gets(a);
	int n = strlen(a);
	forn(i,n) 
		if (a[i] != ' ') b[a[i]]++;
		
	bool flag = 1;
	
	gets(a);
	n = strlen(a);
	forn(i,n) 
		if (a[i] != ' ') { 
			b[a[i]]--;
			if (b[a[i]] < 0) flag = 0;
		}
	if (flag) puts("YES");
	else puts("NO");
		
	
	return 0;
}