#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=100005;

int b[MAXN];
vector <int> G[MAXN*2];
bool vis[MAXN*2],c[MAXN*2];
queue <int> q;

void bfs(int s)
{
	vis[s]=true;
	q.push(s);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if (!vis[v])
			{
				vis[v]=true;
				c[v]=c[u]^1;
				q.push(v);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int g;
		scanf("%d%d",&b[i],&g);
		G[b[i]].pb(g);
		G[g].pb(b[i]);
	}
	for (int i=1;i<=n;i++)
	{
		G[i*2-1].pb(i*2);
		G[i*2].pb(i*2-1);
	}
	for (int i=1;i<=2*n;i++)
		if (!vis[i])
			bfs(i);
	for (int i=0;i<n;i++)
		if (c[b[i]])
			puts("1 2");
		else
			puts("2 1");
	return 0;
}