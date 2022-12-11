#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=1005;

int w,a[MAXN],b[MAXN],f[MAXN],g[MAXN];
bool vis[MAXN];
vector <int> G[MAXN];
queue <int> q;

void bfs(int u)
{
	int sa=0,sb=0;
	for (int i=0;i<=w;i++) g[i]=f[i];
	vis[u]=true;
	q.push(u);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		sa+=a[u];
		sb+=b[u];
		for (int i=w;i>=a[u];i--)
			g[i]=max(g[i],f[i-a[u]]+b[u]);
		for (int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if (!vis[v])
			{
				vis[v]=true;
				q.push(v);
			}
		}
	}
	for (int i=w;i>=sa;i--)
		g[i]=max(g[i],f[i-sa]+sb);
	for (int i=0;i<=w;i++)
		f[i]=g[i];
}

int main()
{
	int n,m;
	scanf("%d%d%d",&n,&m,&w);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
			bfs(i);
	printf("%d",f[w]);
	return 0;
}