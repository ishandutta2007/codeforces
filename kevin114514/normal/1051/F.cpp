#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
#define pli pair<ll,int>
void die(string S){puts(S.c_str());exit(0);}
vector<pii> Tree[100100];
vector<pii> G[100100];
pii extra[22];
int d[22];
int p;
int Fat[100100];
ll ddist[44][100100];
int Anc(int x)
{
	if(Fat[x]==x)
		return x;
	return Fat[x]=Anc(Fat[x]);
}
int n,m;
void Dijkstra(int st,ll *dist)
{
	priority_queue<pli,vector<pli>,greater<pli> > pq;
	for(int i=1;i<=n;i++)
		dist[i]=1ll*inf*inf;
	dist[st]=0;
	pq.push(mp(0,st));
	while(!pq.empty())
	{
		ll di=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(dist[u]!=di)
			continue;
		for(auto p:G[u])
			if(dist[p.first]>di+p.second)
			{
				dist[p.first]=di+p.second;
				pq.push(mp(dist[p.first],p.first));
			}
	}
}
ll Dist[100100];
int Fa[100100][20];
int depth[100100];
void dfs(int u,int fa)
{
	depth[u]=depth[fa]+1;
	Fa[u][0]=fa;
	for(auto p:Tree[u]) if(p.first!=fa)
	{
		int v=p.first;
		int di=p.second;
		Dist[v]=Dist[u]+di;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(depth[u]<depth[v])
		swap(u,v);
	int del=depth[u]-depth[v];
	for(int i=0;i<20;i++)
		if(del>>i&1)
			u=Fa[u][i];
	if(u==v)
		return u;
	for(int i=19;i>=0;i--)
		if(Fa[u][i]!=Fa[v][i])
		{
			u=Fa[u][i];
			v=Fa[v][i];
		}
	return Fa[u][0];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		Fat[i]=i;
	while(m--)
	{
		int u,v,di;
		scanf("%d%d%d",&u,&v,&di);
		int U=Anc(u),V=Anc(v);
		G[u].pb(mp(v,di));
		G[v].pb(mp(u,di));
		if(U==V)
		{
			extra[p]=mp(u,v);
			d[p++]=di;
		}
		else
		{
			Fat[U]=V;
			Tree[u].pb(mp(v,di));
			Tree[v].pb(mp(u,di));
		}
	}
	for(int i=0;i<p;i++)
	{
		Dijkstra(extra[i].first,ddist[i+i+0]);
		Dijkstra(extra[i].second,ddist[i+i+1]);
	}
	dfs(1,0);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			Fa[j][i]=Fa[Fa[j][i-1]][i-1];
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ll ans=Dist[u]+Dist[v]-2*Dist[lca(u,v)];
		for(int i=0;i<p;i++)
		{
			ans=min(ans,ddist[i+i][u]+ddist[i+i+1][v]+d[i]);
			ans=min(ans,ddist[i+i][v]+ddist[i+i+1][u]+d[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}