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
int n,ans;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)if(read())++ans;  // read read  //{ , } //  if() _;
	if(ans)puts("hard");else puts("easy");
}