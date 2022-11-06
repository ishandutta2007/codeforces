#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e9;
ll s=32768;
struct node
{
	int l=-1,r=-1;
	int z=0,o=0;
};
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	// cin>>test;
	while(test--)
	{
		ll n,k;
		cin>>n>>k;
		pair<ll,ll> a[k];
		ll t=0;
		FOR(i,0,k)
		{
			cin>>a[i].first>>a[i].second;
			t+=a[i].second;
		}
		ll o=(n*(n+1))/2;
		if(t<n)
		{
			cout<<1;
		}
		else if(t>n)
		{
			cout<<-1;
		}
		else
		{
			// sort(a,a+k);
			FOR(i,0,k)
			{
				o-=a[i].first*a[i].second;
			}
			o+=n*n;
			if(o%n==0)
			{
				cout<<1;
			}
			else
				cout<<-1;
		}

		
	}
	return 0;
}