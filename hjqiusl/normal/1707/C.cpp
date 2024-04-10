// Lynkcat.
// Problem: C. DFS Trees
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
poly G[N];
int vis[N],tim;
int s[N];
int fa[N];
int Tp[N];
pa E[N];
int st[N][21];
int dfn[N],rdfn[N],DFN;
int id[N];
int cnt;
int dep[N],siz[N],son[N],ffa[N];
int n,m;
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void dfs(int k,int fa)
{
	ffa[k]=fa;
	siz[k]=1;
	dep[k]=dep[fa]+1;
	st[k][0]=fa;
	for (int i=1;i<=20;i++)
		st[k][i]=st[st[k][i-1]][i-1];
	dfn[k]=++DFN;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		siz[k]+=siz[u];
		if (siz[u]>siz[son[k]]) son[k]=u;
	}
	rdfn[k]=DFN;
}
void dfs1(int k,int tp)
{
	Tp[k]=tp;
	if (son[k]) dfs1(son[k],tp);
	for (auto u:G[k])
	{
		if (u==ffa[k]||u==son[k]) continue;
		dfs1(u,u);
	}
}
inline int lca(int x,int y)
{
	while (Tp[x]!=Tp[y])
	{
		if (dep[Tp[x]]<dep[Tp[y]]) swap(x,y);
		x=ffa[Tp[x]];
	}
	if (dep[x]>dep[y]) return y;
	return x;
}
inline int gt(int x,int y)
{
	for (int i=20;i>=0;i--)
		if (dep[st[y][i]]>dep[x]) y=st[y][i];
	return y;
}
void dfs2(int k,int fa)
{
	for (auto u:G[k])
	{
		if (u==fa) continue;
		s[u]+=s[k];
		dfs2(u,k);
	}
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if (gf(x)!=gf(y))
		{
			G[x].push_back(y);
			G[y].push_back(x);
			x=gf(x),y=gf(y);
			fa[x]=y;
			// cout<<x<<","<<y<<endl;
		} else
		{
			E[++cnt]=mp(x,y);
			id[cnt]=i;
		}
	}
	dfs(1,0);
	dfs1(1,1);
	for (int i=1;i<=cnt;i++)
	{
		int x=E[i].fi,y=E[i].se;
		int u=lca(x,y);
		// cout<<x<<","<<y<<" "<<u<<endl;
		if (u!=x&&u!=y)
		{
			s[x]--,s[y]--;
			s[1]++;
		} else
		{
			if (u!=x) swap(x,y);
			int z=gt(x,y);
			s[z]++;
			s[y]--;
		}
	}
	dfs2(1,0);
	for (int i=1;i<=n;i++)
		if (!s[i]) cout<<1;
		else cout<<0;
		cout<<endl;
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}