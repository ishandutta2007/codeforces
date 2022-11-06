#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e9;
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
		int n;
		cin>>n;
		int h=n,a[n];
		vector< pair<int,int> > ans;
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		ll p=0;
		FOR(i,0,n)
		{
			p=max(p,i);
			while(p<n && a[p]!=1)
			{
				p++;
			}
			if(a[i]==2)
			{
				if(p==n)
				{
					cout<<-1;
					return 0;
				}
				ans.pb(mp(h,i+1));
				ans.pb(mp(h,p+1));
				h--;
				a[p]=0;
			}
		}
		p=0;
		h=1;
		FOR(i,0,n)
		{
			p=max(p,i+1);
			while(p<n && a[p]==0)
			{
				p++;
			}
			if(a[i]==0 || a[i]==2)
			{
				continue;
			}
			if(a[i]==1)
			{
				ans.pb(mp(h,i+1));
			}
			else
			{
				if(p==n)
				{
					cout<<-1;
					return 0;
				}
				ans.pb(mp(h,i+1));
				ans.pb(mp(h,p+1));
			}
			h++;
		}
		cout<<ans.size()<<'\n';
		FOR(i,0,ans.size())
		{
			cout<<ans[i].first<<' '<<ans[i].second<<'\n';
		}
	}
	return 0;
}