#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
struct edge
{
	int s,t,d,i;
	bool operator<(const edge& y)const
	{
		return d<y.d;
	}
}e[MAXN*10];
int n,m,M,i,j,k,f[MAXN],F[MAXN][20],G[MAXN][20],d[MAXN],h[MAXN],ne[MAXN<<1],p[MAXN<<1],w[MAXN<<1],u[MAXN*10],v[MAXN*10];
bool b[MAXN*10];
int get(int x)
{
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
void dfs(int x)
{
	int i;
	for(i=1;1<<i<=d[x];i++)
	{
		F[x][i]=F[F[x][i-1]][i-1];
		G[x][i]=max(G[x][i-1],G[F[x][i-1]][i-1]);
	}
	for(i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=F[p[i]][0]=x;
		G[p[i]][0]=w[i];
		d[p[i]]=d[x]+1;
		dfs(p[i]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].d);
		u[i]=e[i].s;
		v[i]=e[i].t;
		e[i].i=i;
	}
	sort(e+1,e+m+1);
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++)if(get(e[i].s)!=get(e[i].t))
	{
		f[get(e[i].s)]=get(e[i].t);
		p[++M]=e[i].t;
		ne[M]=h[e[i].s];
		h[e[i].s]=M;
		w[M]=e[i].d;
		p[++M]=e[i].s;
		ne[M]=h[e[i].t];
		h[e[i].t]=M;
		w[M]=e[i].d;
	}
	else b[e[i].i]=1;
	f[1]=0;
	dfs(1);
	for(i=1;i<=m;i++)if(b[i])
	{
		k=0;
		if(d[u[i]]<d[v[i]])swap(u[i],v[i]);
		if(d[u[i]]!=d[v[i]])for(j=19;~j;j--)if(d[u[i]]-d[v[i]]>>j&1)
		{
			k=max(k,G[u[i]][j]);
			u[i]=F[u[i]][j];
		}
		if(u[i]!=v[i])
		{
			for(j=19;~j;j--)if(F[u[i]][j]!=F[v[i]][j])
			{
				k=max(k,max(G[u[i]][j],G[v[i]][j]));
				u[i]=F[u[i]][j];
				v[i]=F[v[i]][j];
			}
			k=max(k,max(G[u[i]][0],G[v[i]][0]));
		}
		printf("%d\n",k);
	}
	return 0;
}