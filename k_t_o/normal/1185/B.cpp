#include<bits/stdc++.h>
using namespace std;
int n,ss,tt,u,v,wqy,c,d;
char s[2000008],t[2000009];
int main()
{
	scanf("%d",&n);
	while(n--){
		scanf("%s",s+1); scanf("%s",t+1);
		ss=strlen(s+1);
		tt=strlen(t+1); u=1; v=1; wqy=1;
		while(v<=ss){
			c=1; ++v;
			while(s[v]==s[v-1]){   //  //v<=s    //zhongwen 
				++c; ++v;
			}
			d=0;
			while(u<=tt&&t[u]==s[v-1]){
				++u; ++d;
			}
			if(d<c){
				puts("NO");
				wqy=0;
				break;
			}
		}
		if(wqy) if(u>tt) puts("YES");else puts("NO");
	}
}