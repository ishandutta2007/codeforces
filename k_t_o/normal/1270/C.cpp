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
long long S,op,a[300003],n;
int main()
{
	long long T=read();
	while(T--){
		n=read();S=0,op=0;
		for(int i=1;i<=n;++i)a[i]=read(),S+=a[i],op^=a[i];
		puts("2");
		printf("%lld %lld\n",op,S+op);
	}
}