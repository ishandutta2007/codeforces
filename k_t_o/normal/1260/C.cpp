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
long long T,r,b,k,g;
int main()
{
	T=read();
	while(T--){
		r=read(); b=read(); k=read();
		g=__gcd(r,b);r/=g; b/=g;
		if(r<b)swap(r,b);
		if((k-1)*b+1<r)puts("REBEL");
		else puts("OBEY");
	}
}