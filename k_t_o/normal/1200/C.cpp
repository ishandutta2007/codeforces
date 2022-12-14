#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline long long read()
{
	long long ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
long long a,b,c,d,n,m,q,g,ng,mg,aa,cc;//signed
int main()
{
	cin>>n>>m>>q;;
	
	g=__gcd(n,m);
	ng=n/g;
	mg=m/g;
	
	while(q--){
		a=read(); b=read(); c=read(); d=read();
		--b; --d;
		if(a==1)aa=b/ng;else aa=b/mg;
		if(c==1)cc=d/ng;else cc=d/mg;
		if(aa==cc)puts("YES");else puts("NO");
	}
}