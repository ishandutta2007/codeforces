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
int T,m,k,h[124],n;
int main()
{
	T=read();
	while(T--){
		n=read(); m=read(); k=read();
		for(int i=1;i<=n;++i)h[i]=read();
		for(int i=1;i<n;++i){
			m+=h[i]-max(0,h[i+1]-k);
			if(m<0){
				puts("NO");goto lll;
			}
		}puts("YES");
		lll:;
	} 
}