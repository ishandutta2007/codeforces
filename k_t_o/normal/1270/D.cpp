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
#define FF fflush(stdout);
int n,k,p,w,_p,_w,M;
int main()
{
	n=read(); k=read();
	printf("? ");for(int i=1;i<=k;++i)printf("%d ",i);puts("");FF
	p=read(); w=read();
	printf("? ");for(int i=1;i<=k;++i)if(i!=p)printf("%d ",i);printf("%d ",k+1);puts("");FF
	_p=read(); _w=read();
	for(int i=1;i<=k;++i)if(i!=p){
		printf("? ");for(int j=1;j<=k+1;++j)if(j!=i)printf("%d ",j);puts("");FF;
		if(read()==p)++M;read();
	}
	if(_w<w)printf("! %d",M+1);else printf("! %d",k-M);
}