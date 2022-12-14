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
int l,r,x,f[103];
int main()
{
	l=read(); r=read();
	for(int i=l;i<=r;++i) {
		for(int i=0;i<=9;++i)f[i]=0;
		x=i;
		while(x){
			if(f[x%10])goto lll;
			f[x%10]=1;
			x/=10;
		}
		printf("%d\n",i);exit(0);
		lll:;
	}
	puts("-1");
}