#include<bits/stdc++.h>
using namespace std;

char s[110];

int main(){
	gets(s);
	char c = 0;
	for(int i = strlen(s) - 1 ; i >= 0 ; i--)
		if(isupper(s[i]) || islower(s[i])){
			c = s[i];
			break;
		}
	if(c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u' || c == 'Y' || c == 'y')
		puts("YES");
	else
		puts("NO");
	return 0;
}