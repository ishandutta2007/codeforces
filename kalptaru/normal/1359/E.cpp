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
ll fac[500005],ifac[500005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll n,k,r;
		cin>>n>>k;
		fac[0]=1;
		ifac[0]=1;
		FOR(i,1,500005)
		{
			fac[i]=(fac[i-1]*i)%mod;
			ifac[i]=po(fac[i],mod-2);
		}
		ll ans=0,a;
		FOR(i,1,n+1)
		{
			r=n/i;
			if(r<k)
			break;
			a=(((fac[r-1]*ifac[r-k])%mod)*ifac[k-1])%mod;
			ans+=a;
		}
		cout<<ans%mod;
	}
	return 0;
}