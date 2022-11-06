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
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
int w[100005];
bool vi[100005];
vector<int> ans;
bool co[200005]={0};
void dfs(int i,vector<pair<int,int> > gra[])
{
//	cout<<i<<"i\n";
	vi[i]=1;
	FOR(j,0,gra[i].size())
	{
		if(co[gra[i][j].second]==0)
		{
			ans.pb(gra[i][j].second+1);
			w[gra[i][j].first]++;
			co[gra[i][j].second]=1;
		}
	}
	FOR(j,0,gra[i].size())
	{
		if(vi[gra[i][j].first]==0 && gra[gra[i][j].first].size()<=w[gra[i][j].first])
		{
			dfs(gra[i][j].first,gra);
		}
	}
	return;
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
		FOR(i,0,n)
		{
			cin>>w[i];
		}
		vector<pair<int,int> > gra[n];
		int u,v;
		FOR(i,0,m)
		{
			cin>>u>>v;
			gra[u-1].pb(mp(v-1,i));
			gra[v-1].pb(mp(u-1,i));
		}
		FOR(i,0,n)
		{
			if(vi[i]==0 && gra[i].size()<=w[i])
			{
				dfs(i,gra);
			}
		}
		if(ans.size()==m)
		{
			cout<<"ALIVE\n";
			FORD(i,m,0)
			{
				cout<<ans[i]<<' ';
			}
		}
		else
		{
			cout<<"DEAD";
		}
	}
	return 0;
}