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
long long p;
#define MO 1000000007
long long x,n,vv[90],g[103],ans,t;
long long ksm(int p, long long x)
{
	vv[0]=p;
	for(int i=1;i<=60;++i)vv[i]=vv[i-1]*vv[i-1]%MO;
	long long s=1;
	for(int i=60;i>=0;--i){
		if(1ll<<i <= x){
			x-=1ll<<i;
			s=s*vv[i]%MO;
		}
	}
	return s;
}
//__int128 cyb;

int main()
{
	cin>>x>>n;
	for(int i=2;i<=32000;++i)if(x%i==0){
		g[++t]=i;
		while(x%i==0)x/=i;
	}
	if(x>1)g[++t]=x;
	ans=1;
	for(int i=1;i<=t;++i){
		x=g[i];p=x; 
		while(p<=n){
			ans=ans*ksm(x,n/p)%MO;
			if(n/x < p)break; 
			p*=x;
		}
	}
	cout<<ans;
}