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
////
int f[120003],n,m;
#define MO 1000000007
int main()
{
	n=read();m=read();
	f[0]=1; f[1]=2; f[2]=4;
	for(int i=3;i<=100004;++i)f[i]=(f[i-1]+f[i-2])%MO;
	cout<<(f[m]+f[n]-2)%MO;
}