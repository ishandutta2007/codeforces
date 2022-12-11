#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000005;

struct edge
{
	int to,nxt;
}e[MAXN*2];

int n,m,now,ec,first[MAXN],a[MAXN],num[MAXN],p[MAXN],rk[MAXN],id[MAXN],d[MAXN],q[MAXN],dp[MAXN];

inline int idx(int x,int y)
{
	return x*m+y;
}

int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}

inline void uni(int x,int y)
{
	if (x==y) return;
	if (rk[x]>rk[y]) swap(x,y);
	p[y]=x;
	if (rk[x]==rk[y]) rk[x]++;
}

bool cmp1(int e1,int e2)
{
	return a[idx(now,e1)]<a[idx(now,e2)];
}

bool cmp2(int e1,int e2)
{
	return a[idx(e1,now)]<a[idx(e2,now)];
}

inline void addedge(int u,int v)
{
	e[ec]=(edge){v,first[u]};
	first[u]=ec++;
	d[v]++;
}

inline void topo_sort()
{
	int head=0,tail=0;
	for (int i=0;i<n*m;i++)
		if (d[i]==0)
		{
			dp[i]=1;
			q[tail++]=i;
		}
	while (head<tail)
	{
		int u=q[head++];
		for (int i=first[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			dp[v]=max(dp[v],dp[u]+1);
			if (--d[v]==0) q[tail++]=v;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	int cnt=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			scanf("%d",&a[idx(i,j)]);
			num[cnt++]=a[idx(i,j)];
		}
	fill(first,first+cnt,-1);
	for (int i=0;i<cnt;i++) p[i]=i;
	sort(num,num+cnt);
	cnt=unique(num,num+cnt)-num;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			a[idx(i,j)]=lower_bound(num,num+cnt,a[idx(i,j)])-num;
	for (int i=0;i<n;i++)
	{
		now=i;
		for (int j=0;j<m;j++) id[j]=j;
		sort(id,id+m,cmp1);
		for (int j=1;j<m;j++)
			if (a[idx(i,id[j-1])]==a[idx(i,id[j])])
				uni(find(idx(i,id[j-1])),find(idx(i,id[j])));
	}
	for (int j=0;j<m;j++)
	{
		now=j;
		for (int i=0;i<n;i++) id[i]=i;
		sort(id,id+n,cmp2);
		for (int i=1;i<n;i++)
			if (a[idx(id[i-1],j)]==a[idx(id[i],j)])
				uni(find(idx(id[i-1],j)),find(idx(id[i],j)));
	}
	for (int i=0;i<n;i++)
	{
		now=i;
		for (int j=0;j<m;j++) id[j]=j;
		sort(id,id+m,cmp1);
		for (int j=1;j<m;j++)
			if (a[idx(i,id[j-1])]<a[idx(i,id[j])])
				addedge(find(idx(i,id[j-1])),find(idx(i,id[j])));
	}
	for (int j=0;j<m;j++)
	{
		now=j;
		for (int i=0;i<n;i++) id[i]=i;
		sort(id,id+n,cmp2);
		for (int i=1;i<n;i++)
			if (a[idx(id[i-1],j)]<a[idx(id[i],j)])
				addedge(find(idx(id[i-1],j)),find(idx(id[i],j)));
	}
	topo_sort();
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
			printf("%d ",dp[find(idx(i,j))]);
		puts("");
	}
	return 0;
}