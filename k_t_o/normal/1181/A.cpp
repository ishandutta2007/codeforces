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
long long x,y,z;
int main()
{
	cin>>x>>y>>z;//  lld d    d lld//   / chuhao??
	printf("%lld ",(x+y)/z);
	if(x/z+y/z == (x+y)/z){
		puts("0");
		exit(0);
	}
	x=x%z;y=y%z;
	printf("%lld",min(min(x,z-x),min(y,z-y)));
}