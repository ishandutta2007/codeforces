#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

struct edge
{
	int u,v;
}e[MAXN];

struct edge2
{
	int to,nxt;
}e2[MAXN];

int n,m,d[MAXN],ec,first[MAXN];
queue <int> q;

inline void addedge(int u,int v)
{
	e2[ec]=(edge2){v,first[u]};
	first[u]=ec++;
}

inline bool check(int x)
{
	fill(d+1,d+n+1,0);
	fill(first+1,first+n+1,-1);
	ec=0;
	for (int i=1;i<=x;i++)
	{
		d[e[i].u]++;
		addedge(e[i].v,e[i].u);
	}
	while (!q.empty()) q.pop();
	for (int i=1;i<=n;i++)
		if (d[i]==0) q.push(i);
	while (!q.empty())
	{
		if (q.size()>1) return true;
		int u=q.front();q.pop();
		for (int i=first[u];i!=-1;i=e2[i].nxt)
		{
			int v=e2[i].to;
			if (--d[v]==0) q.push(v);
		}
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&e[i].u,&e[i].v);
	int l=0,r=m;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d",r<m?r+1:-1);
	return 0;
}