#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define pb push_back

const int MAXN=300005;

struct edge
{
	int to,id;
}e[MAXN];

int x,a[MAXN],head,tail,ans[MAXN];
LL val[MAXN];
vector <edge> G[MAXN],G2[MAXN];
bool vis[MAXN];

void dfs(int u)
{
	vis[u]=true;
	for (const auto &e:G[u])
	{
		int v=e.to;
		if (!vis[v])
		{
			dfs(v);
			if (val[v]+val[u]>=x)
			{
				ans[head++]=e.id;
				val[u]+=val[v]-x;
			}
			else
				ans[--tail]=e.id;
		}
	}
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int n,m;
	scanf("%d%d%d",&n,&m,&x);
	LL s=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		val[i]=a[i];
		s+=a[i];
	}
	if (s<(LL)(n-1)*x)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb({v,i});
		G[v].pb({u,i});
	}
	head=0;
	tail=n-1;
	dfs(1);
	for (int i=0;i<n-1;i++)
		printf("%d ",ans[i]+1);
	return 0;
}