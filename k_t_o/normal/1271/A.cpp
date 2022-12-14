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
int a,b,c,d,e,f,_,Ans,op;
int main()
{
	a=read(); b=read(); c=read(); d=read(); e=read(); f=read();
	_=min(a,d); b=min(b,c);
	for(int i=0;i<=_;++i){
		op=min(d-i,b);
		Ans=max(Ans,i*e+op*f);
	}
	printf("%d",Ans);
}