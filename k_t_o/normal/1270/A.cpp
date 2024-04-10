#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0,f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret*f;
}
int T,fl,ma,u,k1,k2,n;
int main()
{
	int T=read();
	while(T--){
		fl=0; ma=0; 
		n=read();k1=read();k2=read();
		for(int i=1;i<=k1;++i){
			u=read();
			if(u>ma)ma=u;
		}
		for(int i=1;i<=k2;++i){
			u=read();
			if(u>ma)fl=1;
		}
		if(fl)puts("NO");else puts("YES");
	}
}