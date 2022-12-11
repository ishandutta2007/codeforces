#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=100005;

int c[MAXN];
vector <int> G[MAXN];

bool bfs(int x)
{
	queue <int> q;
	c[x]=0;
	q.push(x);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if (c[v]==-1)
			{
				c[v]=c[u]^1;
				q.push(v);
			}
			else if (c[v]==c[u]) return false;
		}
	}
	return true;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int u,v;m--;)
	{
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	fill(c+1,c+n+1,-1);
	for (int i=1;i<=n;i++)
		if (c[i]==-1&&!bfs(i))
		{
			printf("-1");
			return 0;
		}
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (c[i]==0)
			cnt++;
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++)
		if (c[i]==0)
			printf("%d ",i);
	printf("\n%d\n",n-cnt);
	for (int i=1;i<=n;i++)
		if (c[i]==1)
			printf("%d ",i);
	return 0;
}