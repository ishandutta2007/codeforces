#include <iostream>
#include <cstdio>
using namespace std;

char s[10010], t[10] = {"heidi"};
int pos;

int main() {
	scanf("%s", s);
	for(int i=0; s[i] != '\0'; i++) {
		if(s[i] == t[pos]){
			pos ++;
			if(pos == 5) break;
		}
	}
	if(pos == 5) printf("YES\n");
	else printf("NO\n");
	return 0;
}