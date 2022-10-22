#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 1000005
#define re register
#define inf 1e9
#define eps 1e-10
#define modc 998244353
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

inline ll qpow(ll a,ll b)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1) ans=(ans*base)%modc;
		base=(base*base)%modc;
		b>>=1;
	}
	return ans;
}

ll k[maxn],cnt[maxn];
vector <ll> vec[maxn];

int main()
{
	ll n=read();
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++)
		{
			ll x=read();
			cnt[x]++; vec[i].push_back(x);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll inv=qpow((((n*n)%modc)*k[i])%modc,modc-2);
		for(int j=0;j<k[i];j++)
		{
			ans=(ans+(inv*cnt[vec[i][j]])%modc)%modc;
		}
	}
	cout<<ans<<endl;
	return 0;
}