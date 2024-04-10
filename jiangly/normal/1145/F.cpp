#include<bits/stdc++.h>
const bool a[]={1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1};
char s[11];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;++i){
		if(a[s[0]-'A']!=a[s[i]-'A']){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}