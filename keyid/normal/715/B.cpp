#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define sc second

typedef long long LL;
typedef pair <LL,int> pli;

const int MAXN=1005,MAXM=10005;
const LL INF=0x3f3f3f3f3f3f3f3fLL;

struct edge
{
	int to,w,nxt;
}e[MAXM*2];

int n,ec,first[MAXN],pre[MAXN];
LL d[MAXN],d1[MAXN],d2[MAXN],dt[MAXN];
bool vis[MAXN],cho[MAXM*2];
priority_queue <pli,vector<pli>,greater<pli> > q;

inline void addedge(int u,int v,int w)
{
	e[ec]=(edge){v,w,first[u]};
	first[u]=ec++;
}

void dijkstra(int s,LL d[])
{
	fill(d,d+n,INF);
	d[s]=0;
	q.push(mp(0,s));
	while (!q.empty())
	{
		pli u=q.top();q.pop();
		if (d[u.sc]!=u.fi) continue;
		for (int i=first[u.sc];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			if (d[v]>u.fi+e[i].w)
			{
				d[v]=u.fi+e[i].w;
				q.push(mp(d[v],v));
			}
		}
	}
}

void findx(int s,int t)
{
	if (s==t) return;
	queue <int> q;
	q.push(s);
	vis[s]=true;
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=first[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			if (vis[v]) continue;
			if (d[v]>=d[u]+e[i].w)
			{
				pre[v]=(i^1);
				if (v==t) return;
				vis[v]=true;
				q.push(v);
			}
		}
	}
}

int main()
{
	int m,L,s,t;
	scanf("%d%d%d%d%d",&n,&m,&L,&s,&t);
	fill(first,first+n,-1);
	for (int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for (int i=0;i<ec;i++)
		if (e[i].w==0)
			e[i].w=0x3f3f3f3f;
		else
			cho[i]=true;
	dijkstra(t,d2);
	if (d2[s]<L)
	{
		printf("NO");
		return 0;
	}
	for (int i=0;i<ec;i++)
		if (e[i].w>1000000000)
			e[i].w=1;
	dijkstra(s,d1);
	for (int i=0;i<n;i++) dt[i]=max(d1[i],L-d2[i]);
	fill(d,d+n,INF);
	d[s]=0;
	q.push(mp(0,s));
	while (!q.empty())
	{
		pli u=q.top();q.pop();
		if (d[u.sc]!=u.fi) continue;
		for (int i=first[u.sc];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			LL t=max(dt[v],u.fi+e[i].w);
			if (d[v]>t)
			{
				d[v]=t;
				q.push(mp(d[v],v));
			}
		}
	}
	bool flag=false;
	for (int i=0;i<n;i++)
		if (d[i]+d2[i]<=L)
		{
			findx(s,i);
			int u=i,now=L-d2[i];
			while (u!=s)
			{
				int x=pre[u];
				int v=e[x].to;
				if (!cho[x])
				{
					cho[x]=true;
					e[x].w=now-d[v];
					now=d[v];
				}
				else
					now-=e[x].w;
				u=v;
			}
			flag=true;
			break;
		}
	if (!flag)
	{
		printf("NO");
		return 0;
	}
	puts("YES");
	for (int i=0;i<ec;i+=2)
	{
		printf("%d %d ",e[i|1].to,e[i].to);
		if (cho[i]) printf("%d\n",e[i].w);
		else if (cho[i|1]) printf("%d\n",e[i|1].w);
		else puts("1000000000000000000");
	}
	return 0;
}