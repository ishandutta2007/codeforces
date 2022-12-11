#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=505;

int n,ans_size,d[MAXN][MAXN],e[MAXN];
bool ok[MAXN];
vector <int> G[MAXN];

void bfs(int st)
{
	for (int i=1;i<=n;i++)
		d[st][i]=-1;
	queue <int> q;
	q.push(st);
	d[st][st]=0;
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int v:G[u])
			if (d[st][v]==-1)
			{
				d[st][v]=d[st][u]+1;
				q.push(v);
			}
	}
}

int query(int u)
{
	int ans=INT_MAX;
	for (int v:G[u])
	{
		int ret=0;
		for (int i=1;i<=n;i++)
			if (ok[i]&&d[u][i]<=d[v][i])
				ret++;
		ans=min(ans,ret);
	}
	return ans;
}

void mark(int u,int v)
{
	for (int i=1;i<=n;i++)
		if (d[u][i]<=d[v][i]&&ok[i])
		{
			ok[i]=false;
			ans_size--;
		}
}

void solve()
{
	ans_size=n;
	for (int i=1;i<=n;i++)
		ok[i]=true;
	char s[10];
	for (;;)
	{
		if (ans_size==1)
		{
			for (int i=1;i<=n;i++)
				if (ok[i])
				{
					printf("%d\n",i);
					fflush(stdout);
					scanf("%s",s);
					assert(s[0]=='F');
					return;
				}
		}
		int id,ret=0;
		for (int i=1;i<=n;i++)
		{
			int t=query(i);
			if (t>=ret)
			{
				ret=t;
				id=i;
			}
		}
		printf("%d\n",id);
		fflush(stdout);
		scanf("%s",s);
		if (s[0]=='F')
			return;
		int w;
		scanf("%d",&w);
		mark(id,w);
	}
}

int main()
{
	// #ifdef local
	// 	freopen("read.txt","r",stdin);
	// #endif
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int q;
		scanf("%d",&q);
		for (int j=0;j<q;j++)
			scanf("%d",&e[j]);
		for (int j=1;j<q;j++)
		{
			G[e[j-1]].pb(e[j]);
			G[e[j]].pb(e[j-1]);
		}
	}
	for (int i=1;i<=n;i++)
		bfs(i);
	for (int i=0;i<n;i++)
		solve();
	return 0;
}