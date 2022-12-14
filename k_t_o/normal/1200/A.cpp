#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,o[13];
char s[123456];
int main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='L'){
			for(int j=0;j<=9;++j)if(!o[j]){
				o[j]=1;break;
			}
//			for(int i=0;i<=9;++i)printf("%d",o[i]);
		} else if(s[i]=='R'){
			for(int j=9;j>=0;--j)if(!o[j]){
				o[j]=1;break;
			}
//			for(int i=0;i<=9;++i)printf("%d",o[i]);
		} else {
			o[s[i]-48]=0;
		}
	}for(int i=0;i<=9;++i)printf("%d",o[i]);
}