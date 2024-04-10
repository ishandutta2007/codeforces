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
char a[1000070],b[1000070];
int n,l,ans,o,f[1000070]; //char 
int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	l=strlen(b+1);
	n=strlen(a+1);
	for(int i=2;i<=n;++i)if(a[i]!=a[i-1])f[i]=1;
	for(int i=2;i<=n;++i)f[i]^=f[i-1];
	for(int i=1;i<=l;++i)if(a[i]^b[i])o^=1;
	if(!o)++ans;
	for(int i=l+1;i<=n;++i){
		o^=f[i]^f[i-l];
		if(!o)++ans;
	}
	cout<<ans;
}