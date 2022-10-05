#include <bits/stdc++.h>
using namespace std;

char s[505];
int occ[27];

int main(){
	scanf("%s", s);
	occ[0] = 1;
	for(int i = 0; s[i]; i++){
		s[i] -= 'a' - 1;
		if(!occ[s[i] - 1]){ puts("NO"); return 0; }
		occ[s[i]] = 1;
	}
	puts("YES");
}