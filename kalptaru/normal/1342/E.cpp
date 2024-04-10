#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
ll fac[200005],ifac[200005];
ll C(int n,int r)
{
	return((((fac[n]*ifac[n-r])%mod)*ifac[r])%mod);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		ll k;
		cin>>n>>k;
		if(k>=n)
		{
			cout<<0;
			return 0;
		}
		fac[0]=1;
		ifac[0]=1;
		FOR(i,1,n+2)
		{
			fac[i]=(fac[i-1]*i)%mod;
			ifac[i]=po(fac[i],mod-2);
		}
		ll ans=C(n,k);
//		FOR(i,0,n+1)
//		cout<<fac[i]<<' '<<i<<'\n';
//		cout<<fac[n]<<' '<<k<<' '<<ans;
		ll t=0;
		int c=n-k;
		FOR(i,0,c)
		{
			if(i%2==0)
			{
				t=(t+((C(c,i)*po((c-i),n))%mod))%mod;
			}
			else
			{
				t=(t-((C(c,i)*po((c-i),n))%mod)+mod)%mod;
			}
		}
		if(k>0)
		ans=(ans*2)%mod;
		cout<<(ans*t)%mod;
	}
	return 0;
}