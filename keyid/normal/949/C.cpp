#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

const int MAXN=100005;

int u[MAXN],clo,pre[MAXN],sccno[MAXN],scc_cnt;
vector <int> G[MAXN],scc[MAXN];
stack <int> s;
bool vis[MAXN];

int dfs(int u)
{
	int lowu=pre[u]=++clo;
	s.push(u);
	for (int v:G[u])
		if (!pre[v])
			lowu=min(lowu,dfs(v));
		else if (!sccno[v])
			lowu=min(lowu,pre[v]);
	if (pre[u]==lowu)
	{
		scc_cnt++;
		for (;;)
		{
			int x=s.top();s.pop();
			sccno[x]=scc_cnt;
			scc[scc_cnt].pb(x);
			if (x==u)
				break;
		}
	}
	return lowu;
}

int main()
{
	int n,m,h;
	scanf("%d%d%d",&n,&m,&h);
	for (int i=1;i<=n;i++)
		scanf("%d",&u[i]);
	for (int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (u[x]==(u[y]+1)%h)
			G[y].pb(x);
		if (u[y]==(u[x]+1)%h)
			G[x].pb(y);
	}
	for (int i=1;i<=n;i++)
		if (!pre[i])
			dfs(i);
	for (int i=1;i<=scc_cnt;i++)
	{
		vis[i]=true;
		for (int u:scc[i])
			for (int v:G[u])
				if (sccno[v]!=i)
				{
					vis[i]=false;
					break;
				}
	}
	int ans=INT_MAX;
	for (int i=1;i<=scc_cnt;i++)
		if (vis[i])
			ans=min(ans,(int)scc[i].size());
	for (int i=1;i<=scc_cnt;i++)
		if (vis[i]&&scc[i].size()==ans)
		{
			printf("%d\n",ans);
			for (int x:scc[i])
				printf("%d ",x);
			break;
		}
	return 0;
}