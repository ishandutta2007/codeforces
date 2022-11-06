#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;

ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
		}
		a=(a*a);
		b>>=1;
	}
	return re;
}
int deg[300005],d[300005];
bool vis[300005],ans[300005];
int ka;
bool dfs(int i,int j,vector< pair<int,int> > gra[])
{
	if(vis[i])
	return 0;
	vis[i]=1;
	bool c;
	FOR(k,0,gra[i].size())
	{
		if(gra[i][k].first!=j)
		{
			c=dfs(gra[i][k].first,i,gra);
			if(c)
			{
				ans[gra[i][k].second]=1;
				ka--;
				deg[i]--;
			}
		}
	}
	if(d[i]==-1)
	return 0;
	if(deg[i]%2 != d[i])
	return 1;
	return 0;
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
		int n,m;
		cin>>n>>m;
		ka=m;
		vector<pair<int,int> > gra[n];
		int root=-1;
		FOR(i,0,n)
		{
			cin>>d[i];
			if(d[i]==-1)
			root=i;
		}
		int u,v;
		FOR(i,0,m)
		{
			cin>>u>>v;
			gra[u-1].pb(mp(v-1,i));
			gra[v-1].pb(mp(u-1,i));
			deg[u-1]++;
			deg[v-1]++;
		}
		if(root==-1)
		{
			int c=0;
			root=0;
			FOR(i,0,n)
			{
				if(deg[i]%2 != d[i])
				c++;
			}
			if(c%2==1)
			{
				cout<<-1;
				return 0;
			}
		}
		dfs(root,-1,gra);
		cout<<ka<<'\n';
		FOR(i,0,m)
		{
			if(ans[i]==0)
			cout<<i+1<<' ';
		}
	}
	return 0;
}