#include<bits/stdc++.h>
using namespace std;

char s[3];
char t[3];

int main()
{
	scanf("%s",s);
	for(int j=1;j<=5;j++){
		scanf("%s",t);
		if(t[0]==s[0]||t[1]==s[1]){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}