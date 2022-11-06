#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=998244353;
// ll mod=1e9+7;
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
		ll a[6];
		FOR(i,0,6)
		{
			cin>>a[i];
		}
		int n;
		cin>>n;
		pair<ll,int> pr[6*n];
		ll b;
		int cnt[n]={0};
		FOR(i,0,n)
		{
			cin>>b;
			FOR(j,0,6)
			{
				pr[6*i+j]=mp(b-a[j],i);	
			}
		}
		sort(pr,pr+6*n);
		ll p=0,c=0;
		ll ans=INF;
		FOR(i,0,6*n)
		{
			while(p<6*n && c<n)
			{
				if(cnt[pr[p].second]==0)
				{
					c++;
				}
				cnt[pr[p].second]++;
				p++;
			}
			if(c==n)
			ans=min(ans,pr[p-1].first-pr[i].first);
			// cout<<ans<<' ';
			if(cnt[pr[i].second]==1)
			{
				c--;
			}
			cnt[pr[i].second]--;
		}
		cout<<ans;
	}
	return 0;
}