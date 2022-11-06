#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
const ll mod=1e9+7;
ll INF=1e18;
const ll N=4000005;
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
ll a[N],b[N],p[N];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("azerah.in", "r", stdin);
    // freopen("azerah.out", "w", stdout);
    // ll gtest=0;
    // spre
    
	ll test=1;
	// int gt=0;
	// cin>>test;
	while(test--)
	{
		ll n,m;
		cin>>n>>m;
		a[1]=1;
		p[1]=1;
		for(ll j=1;j<=n;j+=1)
		{
			b[j]=(b[j]+1+m)%m;
		}
		for(ll j=2;j<=n;j+=2)
		{
			b[j]=(b[j]-1+m)%m;
		}
		FOR(i,2,n+1)
		{
			
			b[i]=(b[i]+b[i-1])%m;
			a[i]=(p[i-1]+b[i])%m;
			p[i]=(a[i]+p[i-1])%m;
			// cout<<a[i]<<' ';
			for(ll j=i;j<=n;j+=i)
			{
				b[j]=(b[j]+a[i]+m)%m;
			}
			for(ll j=(i+1);j<=n;j+=(i+1))
			{
				b[j]=(b[j]-a[i]+m)%m;
			}
		}
		cout<<a[n]%m;
	}

	return 0;
}