#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

struct edge
{
	int to,nxt;
}e[MAXN*2];

int ec,first[MAXN],vis[MAXN];
bool c[MAXN],vis2[MAXN];
vector <int> G[MAXN];
queue <int> q;

void addedge(int u,int v)
{
	e[ec]=(edge){v,first[u]};
	first[u]=ec++;
}

bool dfs(int u)
{
	vis[u]=-1;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (!vis[v])
			c[v]=dfs(v);
		if (vis[v]==-1||c[v]) return true;
	}
	vis[u]=1;
	return false;
}

int bfs(int u)
{
	bool f=true;
	int cnt=0;
	q.push(u);
	vis2[u]=true;
	while (!q.empty())
	{
		cnt++;
		int u=q.front();q.pop();
		if (c[u]) f=false;
		for (int i=first[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			if (!vis2[v])
			{
				vis2[v]=true;
				q.push(v);
			}
		}
	}
	if (f) cnt--;
	return cnt;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	fill(first+1,first+n+1,-1);
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
		G[u].push_back(v);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
			c[i]=dfs(i);
	int ans=0;
	for (int i=1;i<=n;i++)
		if (!vis2[i])
			ans+=bfs(i);
	printf("%d",ans);
	return 0;
}