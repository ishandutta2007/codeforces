#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
//ll mod=163577857;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return re;
}
vector<pair<int,int> > ver[200005],hor[200005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,w,h;
		cin>>n>>w>>h;
		int g,p,t;
		pair<int,int> ans[n];
		FOR(i,0,n)
		{
			cin>>g>>p>>t;
			t-=p;
			t+=100000;
			if(g==1)
			{
				ver[t].pb(mp(p,i));
			}
			else
			{
				hor[t].pb(mp(p,i));
			}
		}
		FOR(i,1,200005)
		{
			sort(ver[i].begin(),ver[i].end());
			sort(hor[i].begin(),hor[i].end());
			int vs=ver[i].size(),hs=hor[i].size();
//			if(i<40)
//			cout<<i<<' '<<vs<<' '<<hs<<'\n';
			if(vs<hs)
			{
				FOR(j,0,vs)
				{
					ans[hor[i][hs-j-1].second]=mp(ver[i][j].first,h);
				}
				FOR(j,vs,hs)
				{
					ans[hor[i][hs-j-1].second]=mp(w,hor[i][hs-j+vs-1].first);
				}
				FOR(j,0,vs)
				{
					ans[ver[i][j].second]=mp(w,hor[i][vs-j-1].first);
				}
			}
			else if(hs<vs)
			{
				FOR(j,0,hs)
				{
					ans[hor[i][hs-j-1].second]=mp(ver[i][j].first,h);
				}
				FOR(j,hs,vs)
				{
					ans[ver[i][j-hs].second]=mp(ver[i][j].first,h);
				}
				FOR(j,0,hs)
				{
					ans[ver[i][j+vs-hs].second]=mp(w,hor[i][hs-j-1].first);
				}
			}
			else
			{
				FOR(j,0,vs)
				{
					ans[hor[i][hs-j-1].second]=mp(ver[i][j].first,h);
					ans[ver[i][j].second]=mp(w,hor[i][hs-j-1].first);
				}
			}
		}
		FOR(i,0,n)
		{
			cout<<ans[i].first<<' '<<ans[i].second<<'\n';
		}	
	}
	return 0;
}