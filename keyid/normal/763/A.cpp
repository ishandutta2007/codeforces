#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=100005;

int c[MAXN];
bool ok[MAXN],ok2[MAXN];
vector <int> G[MAXN];

void dfs(int u,int fa)
{
	ok[u]=ok2[u]=true;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (v!=fa)
		{
			dfs(v,u);
			if (c[v]!=c[u]||!ok[v])
				ok[u]=false;
			if (!ok[v])
				ok2[u]=false;
		}
	}
}

int root;

bool dfs2(int u,int fa,int cc)
{
	if (ok2[u])
	{
		root=u;
		return true;
	}
	if (cc!=c[u]) return false;
	int cnt=0;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (v!=fa)
		{
			if (c[v]!=cc)
				cnt++;
		}
	}
	if (cnt>1) return false;
	if (cnt==0)
	{
		int cnt2=0;
		for (int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if (v!=fa)
				if (!ok[v])
					cnt2++;
		}
		if (cnt2>1) return false;
		if (cnt2==0)
			for (int i=0;i<G[u].size();i++)
			{
				int v=G[u][i];
				if (v!=fa)
					if (dfs2(v,u,cc))
						return true;
			}
		else
			for (int i=0;i<G[u].size();i++)
			{
				int v=G[u][i];
				if (v!=fa)
					if (!ok[v])
						return dfs2(v,u,cc);
			}
		return false;
	}
	else
	{
		for (int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if (v!=fa)
				if (c[v]==c[u]&&!ok[v])
					return false;
		}
		for (int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if (v!=fa)
				if (c[v]!=c[u])
					return dfs2(v,u,cc);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(1,0);
	if (dfs2(1,0,c[1]))
		printf("YES\n%d",root);
	else printf("NO");
	return 0;
}