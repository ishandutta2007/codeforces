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
int n,d,m,x,y;
int main()
{
	n=read();d=read();
	m=read();
	for(int i=1;i<=m;++i){
		x=read(),y=read(); //ab () ()
		if(abs(x-y) > d)puts("No");else 
		if(x+y<d || x+y > (n<<1)-d)puts("No");else puts("Yes");
	}
}