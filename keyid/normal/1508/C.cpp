#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=200005,MAXN2=1005;

struct edge
{
	int u,v,w;
}e[MAXN];

struct edge2
{
	int u,v;
}e2[MAXN2];

int p[MAXN];
bool vis[MAXN2][MAXN2];
set <int> s;
vector <int> G[MAXN];

int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}

void bfs(int u)
{
	queue <int> q;
	q.push(u);
	s.erase(u);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		int head=0;
		for (auto it=s.begin();it!=s.end();)
		{
			while (head<G[u].size()&&G[u][head]<*it)
				head++;
			if (head<G[u].size()&&G[u][head]==*it)
				++it;
			else
			{
				p[*it]=u;
				q.push(*it);
				s.erase(it++);
			}
		}
	}
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for (int i=1;i<=n;i++)
		p[i]=i;
	for (int i=1;i<=n;i++)
		s.insert(i);
	for (int i=0;i<m;i++)
	{
		G[e[i].u].pb(e[i].v);
		G[e[i].v].pb(e[i].u);
	}
	for (int i=1;i<=n;i++)
		sort(G[i].begin(),G[i].end());
	while (!s.empty())
		bfs(*s.begin());
	sort(e,e+m,[](const edge &a,const edge &b) {
		return a.w<b.w;
	});
	if ((LL)n*(n-1)/2-m<n)
	{
		LL ans=0;
		for (int i=0;i<m;i++)
			ans^=e[i].w;
		for (int i=0;i<m;i++)
		{
			int u=find(e[i].u),v=find(e[i].v);
			if (u!=v)
			{
				p[u]=v;
				ans+=e[i].w;
			}
		}
		for (int i=0;i<m;i++)
			vis[e[i].u][e[i].v]=vis[e[i].v][e[i].u]=true;
		int cnt=0;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (!vis[i][j])
					e2[cnt++]={i,j};
		for (int i=0;i<cnt;i++)
		{
			for (int j=1;j<=n;j++)
				p[j]=j;
			for (int j=0;j<cnt;j++)
				if (j!=i)
					p[find(e2[j].u)]=find(e2[j].v);
			LL sum=0;
			for (int i=0;i<m;i++)
			{
				int u=find(e[i].u),v=find(e[i].v);
				if (u!=v)
				{
					p[u]=v;
					sum+=e[i].w;
				}
			}
			ans=min(ans,sum);
		}
		printf("%lld\n",ans);
	}
	else
	{
		LL sum=0;
		for (int i=0;i<m;i++)
		{
			int u=find(e[i].u),v=find(e[i].v);
			if (u!=v)
			{
				p[u]=v;
				sum+=e[i].w;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}