#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=100005;

int maxbit,deep[MAXN],fa[20][MAXN];
bool is_root[MAXN],f[20][MAXN],g[20][MAXN];
vector <int> G[MAXN];

void dfs(int u)
{
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		deep[v]=deep[u]+1;
		dfs(v);
	}
}

int LCA(int u,int v)
{
	if (deep[u]>deep[v])
		swap(u,v);
	for (int i=maxbit;i>=0;i--)
		if (deep[fa[i][v]]>=deep[u])
			v=fa[i][v];
	if (u==v) return u;
	for (int i=maxbit;i>=0;i--)
		if (fa[i][u]!=fa[i][v])
		{
			u=fa[i][u];
			v=fa[i][v];
		}
	if (fa[0][u]!=fa[0][v])
		return 0;
	return fa[0][u];
}

bool check1(int u,int v)
{
	if (deep[v]<=deep[u]) return false;
	bool ret=true;
	for (int i=maxbit;i>=0;i--)
		if (deep[fa[i][v]]>=deep[u])
		{
			ret=ret&&f[i][v];
			v=fa[i][v];
		}
	return u==v&&ret;
}

bool check2(int u,int v)
{
	int lca=LCA(u,v);
	if (lca==0||lca==v) return false;
	if (lca==u||check1(lca,u))
	{
		bool ret=true;
		for (int i=maxbit;i>=0;i--)
			if (deep[fa[i][v]]>=deep[lca])
			{
				ret=ret&&g[i][v];
				v=fa[i][v];
			}
		return ret;
	}
	return false;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int p,t;
		scanf("%d%d",&p,&t);
		if (p!=-1)
		{
			G[p].pb(i);
			fa[0][i]=p;
			if (t==0)
				f[0][i]=true;
			else
				g[0][i]=true;
		}
		else
			is_root[i]=true;
	}
	for (int i=1;i<=n;i++)
		if (is_root[i])
		{
			deep[i]=1;
			dfs(i);
		}
	while ((1<<maxbit)<n) maxbit++;maxbit--;
	for (int j=1;j<=maxbit;j++)
		for (int i=0;i<=n;i++)
		{
			fa[j][i]=fa[j-1][fa[j-1][i]];
			f[j][i]=f[j-1][i]&&f[j-1][fa[j-1][i]];
			g[j][i]=g[j-1][i]&&g[j-1][fa[j-1][i]];
		}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int ty,u,v;
		scanf("%d%d%d",&ty,&u,&v);
		if (ty==1)
			puts(check1(u,v)?"YES":"NO");
		else
			puts(check2(u,v)?"YES":"NO");
	}
	return 0;
}