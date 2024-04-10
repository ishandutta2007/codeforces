#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Edge{
	ll to,prev,dist;
};
Edge ed[MAXN<<1];
ll n,tot,from,to,dist,qcnt,x,mx,res;
li d;
ll last[MAXN],fa[MAXN],ffa[MAXN],u[MAXN],v[MAXN];
li f[MAXN],g[MAXN];
inline li read()
{
    register li num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline void addEdge(ll from,ll to,ll dist)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	ed[tot].dist=dist;
	last[from]=tot;
}
inline void update(ll node,li d)
{
	(g[node]=max(g[node],d))>f[node]?swap(g[node],f[node]):(void)1;
}
inline void dfs(ll node,ll fa)
{
	ll to;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		(to=ed[i].to)!=fa?dfs(to,node),update(node,f[to]+ed[i].dist):(void)1;
	}
}
inline void dfs2(ll node,ll fa)
{
	ll to;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if((to=ed[i].to)!=fa)
		{
			update(to,ed[i].dist+(f[to]+ed[i].dist==f[node]?g[node]:f[node]));
			dfs2(to,node);
		}
	}
	for(register int i=last[node];i;i=ed[i].prev)
	{
		to=ed[i].to;
		(f[node]==f[to]?node<to:f[node]<f[to])?::fa[to]=node:(::fa[node]=to);
	}
}
inline ll find(ll x)
{
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
inline void solve()
{
	for(register int i=1;i<=n;i++)
	{
		ffa[i]=i,v[i]=1;
	}
	for(register int i=n,j=n;i>=1;i--)
	{
		while(f[u[j]]>f[u[i]]+d)
		{
			v[find(u[j--])]--;
		}
		res=max(res,v[u[i]]),v[ffa[u[i]]=fa[u[i]]]+=v[u[i]];
	}
	printf("%d\n",res);
}
int main()
{
	n=read();
	for(register int i=0;i<n-1;i++)
	{
		from=read(),to=read(),dist=read();
		addEdge(from,to,dist),addEdge(to,from,dist);
	}	
	dfs(1,0),dfs2(1,0),qcnt=read();
	for(register int i=1;i<=n;i++)
	{
		u[i]=i;
	}
	sort(u+1,u+n+1,[](ll x,ll y){return f[x]==f[y]?x<y:f[x]<f[y];});
	for(register int i=0;i<qcnt;i++)
	{
		d=read(),res=0,solve();
	}
}