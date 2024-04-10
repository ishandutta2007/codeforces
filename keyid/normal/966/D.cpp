#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=300005;

int n,d[MAXN],pre[MAXN];
bool vis[MAXN];
vector <int> G[MAXN],com;
queue <int> q;

void bfs(int s)
{
	for (int i=1;i<=n;i++)
		d[i]=-1;
	d[s]=0;
	q.push(s);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int v:G[u])
			if (d[v]==-1)
			{
				pre[v]=u;
				d[v]=d[u]+1;
				q.push(v);
			}
	}
}

void dfs(int u)
{
	com.pb(u);
	for (int v:G[u])
		if (!vis[v])
		{
			vis[v]=true;
			dfs(v);
		}
}

void find_com(int s)
{
	com.clear();
	vis[s]=true;
	dfs(s);
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	bfs(1);
	if (d[n]>0&&d[n]<=4)
	{
		printf("%d\n",d[n]);
		stack <int> sta;
		while (n)
		{
			sta.push(n);
			n=pre[n];
		}
		while (!sta.empty())
		{
			printf("%d ",sta.top());
			sta.pop();
		}
	}
	else
	{
		int p=0;
		for (int i=1;i<=n;i++)
			if (d[i]==2)
			{
				p=i;
				break;
			}
		if (p)
			printf("4\n1 %d %d 1 %d\n",pre[p],p,n);
		else
		{
			for (int i=1;i<=n;i++)
				for (auto k=G[i].begin();k!=G[i].end();++k)
					if (*k==1)
					{
						G[i].erase(k);
						break;
					}
			for (int s:G[1])
			{
				find_com(s);
				for (int u:com)
					if (G[u].size()<com.size()-1)
					{
						bfs(u);
						for (int v:com)
							if (d[v]==2)
							{
								printf("5\n1 %d %d %d %d %d",u,pre[v],v,u,n);
								return 0;
							}
					}
			}
			printf("-1");
		}
	}
	return 0;
}