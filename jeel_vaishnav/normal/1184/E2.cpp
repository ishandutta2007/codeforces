#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;
const int M = 1e5 + 5;
const int LG = 20;

int n, m;
int level[N];
int32_t maxwt[LG][M], parentt[LG][M];
int storeu[N], storev[N], storew[N];
int dist[N], parent[N];
bool vis[N];
vector<pair<int, int> > g[N], tree[N];

int primsMST(int source) //Finds the cost and makes the MST
{
	for(int i=1;i<=n;i++)
		dist[i] = 1e9;
	set<pair<int, int> > s;
	s.insert({0, source});
	int cost=0;
	dist[source]=0;
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		if(vis[x.second])
			continue;
		vis[x.second]=1;
		cost+=x.first;
		int u=x.second;
		int v=parent[x.second];
		int w=x.first;
		tree[u].push_back({v, w});
		tree[v].push_back({u, w});
		for(auto it:g[x.second])
		{
			if(vis[it.first])
				continue;
			if(dist[it.first] > it.second)
			{
				s.erase({dist[it.first], it.first});
				dist[it.first]=it.second;
				s.insert({dist[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	return cost;
}

void dfs(int k, int par, int w, int lvl)
{	
	level[k]=lvl;
	maxwt[0][k]=w;
	parentt[0][k]=par;
	for(auto it:tree[k])
	{
		if(it.first==par)
			continue;
		dfs(it.first, k, it.second, lvl+1);
	}
}	

void precompute()
{
	for(int j=1;j<LG;j++)
	{
		for(int i=1;i<=n;i++)
		{
			parentt[j][i]=parentt[j-1][parentt[j-1][i]];
			maxwt[j][i]=max(maxwt[j-1][i], maxwt[j-1][parentt[j-1][i]]);
		}
	}
}

int LCA(int u, int v)
{
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	int ans=0;
	for(int i=LG-1;i>=0;i--)
	{
		if((1<<i) & diff)
		{
			ans=max(ans, (int)maxwt[i][u]);
			u=parentt[i][u];
		}
	}
	if(u==v)
		return ans;
	for(int i=LG-1;i>=0;i--)
	{
		if(parentt[i][u] && parentt[i][u]!=parentt[i][v])
		{
			ans=max(ans, (int)maxwt[i][u]);
			ans=max(ans, (int)maxwt[i][v]);
			u=parentt[i][u];
			v=parentt[i][v];
		}
	}
	ans=max(ans, (int)maxwt[0][u]);
	ans=max(ans, (int)maxwt[0][v]);
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		storeu[i]=u, storev[i]=v, storew[i]=w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	int ans = primsMST(1);
	dfs(1, 1, 0, 1);
	precompute();
	for(int i=1;i<=m;i++)
	{
		int remove=LCA(storeu[i], storev[i]);
		int cur = storew[i] - remove;
		if(cur > 0)
			cout << remove << endl;
	}
	return 0;
}