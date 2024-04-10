#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=200005;

vector <int> G[MAXN];
int clo,p[MAXN*2];
bool vis[MAXN];

void dfs(int u)
{
	vis[u]=true;
	p[clo++]=u;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (!vis[v])
		{
			dfs(v);
			p[clo++]=u;
		}
	}
}

int main()
{
	//freopen("read.txt","r",stdin);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1);
	int lim=(clo+k-1)/k;
	int now=0;
	for (int i=0;i<clo;i+=lim)
	{
		now++;
		int r=min(clo,i+lim);
		printf("%d",r-i);
		for (int j=i;j<r;j++)
			printf(" %d",p[j]);
		puts("");
	}
	for (int i=now;i<k;i++)
		puts("1\n1");
	return 0;
}