#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Edge{
	ll to,prev,dist;
};
Edge ed[MAXN<<1];
ll n,u,v,w,len,tot;
li res;
ll last[MAXN],sz[MAXN];
li f[MAXN],g[MAXN];
char ch[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
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
inline void dfs(ll node,ll fa)
{
	sz[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa)
		{
			dfs(ed[i].to,node),sz[node]+=sz[ed[i].to];
			f[node]+=ed[i].dist?sz[ed[i].to]:f[ed[i].to];
		}
	}
}
inline void dfs2(ll node,ll fa)
{
	ll to;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if((to=ed[i].to)!=fa)
		{
			g[to]=ed[i].dist?sz[1]-sz[to]:g[node]+f[node]-f[to],dfs2(to,node);
		}
	}
}
int main()
{
	n=read();
	for(register int i=0;i<n-1;i++)
	{
		u=read(),v=read(),scanf("%s",ch+1),w=1,len=strlen(ch+1);
		for(register int j=1;j<=len;j++)
		{
			w&=(ch[j]=='4'||ch[j]=='7');
		}
		addEdge(u,v,w),addEdge(v,u,w);
	}
	dfs(1,0),dfs2(1,0);
	for(register int i=1;i<=n;i++)
	{
		res+=f[i]*(f[i]-1)+g[i]*(g[i]-1)+2*f[i]*g[i];
	}	
	printf("%lld\n",res);
}