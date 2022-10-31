// Hydro submission #62c566818672efa577bec7eb@1657104002123
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#define inv(x) (fastpow((x),mod-2))
using namespace std;
typedef long long ll;

template <typename T> void read (T &t)
{
	t=0;int f=0;char c=getchar();
	while(!isdigit(c)){f|=c=='-';c=getchar();}
	while(isdigit(c)){t=t*10+c-'0';c=getchar();}
	if(f)t=-t;
}

const int maxk=5000+5;
const ll mod=1e9+7;


ll n,k; 
ll s[maxk][maxk];

ll fastpow(ll a,ll b)
{
	ll re=1,base=a;
	while(b)
	{
		if(b&1)
			re=re*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return re;
}

int main()
{
	read(n),read(k);
	s[0][0]=1;
	for(register ll i=1;i<=k;++i)
		for(register ll j=1;j<=i;++j)
			s[i][j]=(s[i-1][j-1]+j*s[i-1][j]%mod)%mod;
	ll kkk=1,ans=0;
	for(register ll j=0;j<=min(n,k);++j)
	{
		ans=(ans+s[k][j]*kkk%mod*fastpow(2,n-j)%mod)%mod;
		kkk=kkk*(n-j)%mod;
	}
	printf("%lld",ans);
	return 0;
}