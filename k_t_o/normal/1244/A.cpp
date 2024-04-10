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
int t,a,b,c,d,A,B,k;
int main()
{
	t=read(); //(-1)/c //()
	while(t--){
		a=read(); b=read(); c=read(); d=read(); k=read();
		A=(a+c-1)/c; B=(b+d-1)/d;
		if(A+B<=k)cout<<A<<' '<<B<<endl;else puts("-1");
	} 
}