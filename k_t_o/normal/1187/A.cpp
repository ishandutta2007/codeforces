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
int T,n,s,t,d;
int main()
{
	T=read();
	while(T--) {
		n=read(); s=read(); t=read();
		d=n;// d=min(d,s+1); d=min(d,t+1);
		d=min(d,max(n-s+1,n-t+1));
		cout<<d<<endl;
	}
}