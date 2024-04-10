#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=200005;

vector <int> G[MAXN*2];
bool vis[MAXN*2];

void bfs(int st)
{
	vis[st]=true;
	queue <int> q;
	q.push(st);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int v:G[u])
			if (!vis[v])
			{
				vis[v]=true;
				q.push(v);
			}
	}
}

int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(n+v);
		G[n+v].pb(u);
	}
	int ans=0;
	for (int i=1;i<=n+m;i++)
		if (!vis[i])
		{
			ans++;
			bfs(i);
		}
	printf("%d",ans-1);
	return 0;
}