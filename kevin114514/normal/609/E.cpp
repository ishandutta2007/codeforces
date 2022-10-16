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
void die(string S){puts(S.c_str());exit(0);}
//vector<pii> G[200200];
bool MST[200200];
vector<pii> G[200200];
struct edge
{
	int u,v,w,ind;
	edge(int _u=0,int _v=0,int _w=0,int _ind=0)
	{
		u=_u;
		v=_v;
		w=_w;
		ind=_ind;
	}
	friend bool operator <(const edge &a,const edge &b)
	{
		return a.w<b.w;
	}
}Edge[200200];
int U[200200],V[200200],W[200200];
int Fa[200200];
inline int anc(int u)
{
	if(u==Fa[u])
		return u;
	return Fa[u]=anc(Fa[u]);
}
int depth[200100];
int fa[200100][20];
int mx[200100][20];
void dfs(int u,int f)
{
	depth[u]=depth[f]+1;
	fa[u][0]=f;
	for(auto p:G[u]) if(p.first!=f)
	{
		mx[p.first][0]=Edge[p.second].w;
		dfs(p.first,u);
	}
}
int lca(int u,int v)
{
	int ans=0;
	if(depth[u]<depth[v])
		swap(u,v);
	int delta=depth[u]-depth[v];
	for(int i=0;i<20;i++)
		if(delta>>i&1)
		{
			ans=max(ans,mx[u][i]);
			u=fa[u][i];
		}
	if(u==v)
		return ans;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
		{
			ans=max(ans,mx[u][i]);
			ans=max(ans,mx[v][i]);
			u=fa[u][i];
			v=fa[v][i];
		}
	return max(ans,max(mx[u][0],mx[v][0]));
}
ll res[200200];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		Fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		U[i]=u;
		V[i]=v;
		W[i]=w;
		edge e(u,v,w,i);
		Edge[i]=e;
	}
	sort(Edge+1,Edge+m+1);
	ll sum=0;
	for(int i=1;i<=m;i++)
	{
		int u=Edge[i].u,v=Edge[i].v,w=Edge[i].w;
		u=anc(u);
		v=anc(v);
		if(u!=v)
		{
//			cout<<u<<" "<<v<<endl;
			sum+=w;
			MST[i]=1;
			Fa[u]=v;
			G[u].pb(mp(v,i));
			G[v].pb(mp(u,i));
		}
	}
	dfs(1,0);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			mx[j][i]=max(mx[j][i-1],mx[fa[j][i-1]][i-1]);
	for(int i=1;i<=m;i++)
		if(MST[i])
			res[Edge[i].ind]=sum;
		else	res[Edge[i].ind]=sum-lca(Edge[i].u,Edge[i].v)+Edge[i].w;
	for(int i=1;i<=m;i++)
		cout<<res[i]<<endl;
	return 0;
}