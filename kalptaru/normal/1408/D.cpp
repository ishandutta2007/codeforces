#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
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
int cnt[1000005];
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
		int n,m;
		cin>>n>>m;
		pair<int,int> rob[n],lig[m];
		FOR(i,0,n)
		{
			cin>>rob[i].first>>rob[i].second;
		}
		FOR(i,0,m)
		{
			cin>>lig[i].first>>lig[i].second;
		}
		vector<pair<int,pair<int,int> > >fm;
		int ma=0,o;
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(lig[j].first>=rob[i].first)
				{
					fm.pb(mp(lig[j].first-rob[i].first+1,mp(i,j)));
					o=max(lig[j].second-rob[i].second+1,0);
					cnt[o]++;
					ma=max(ma,o);
				}
			}
		}
		sort(fm.begin(),fm.end());
		pair<int,pair<int,int> > tem;
		int ans=ma;
		FOR(d,0,fm.size())
		{
			tem=fm[d];
			int i=tem.second.first,j=tem.second.second,rm=tem.first;
			o=max(lig[j].second-rob[i].second+1,0);
			cnt[o]--;
			while(ma>0 && cnt[ma]==0)
			{
				ma--;
			}
			ans=min(ans,rm+ma);
		}
		cout<<ans<<'\n';
	}
	return 0;
}