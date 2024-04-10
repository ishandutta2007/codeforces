#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e3+51;
struct Edge{
	ll to,prev;
};
struct EdgeForSpfa{
	ll to,prev,dist;
};
Edge ed[MAXN<<1],edr[MAXN<<1];
EdgeForSpfa edd[MAXN];
queue<ll>q;
ll nc,ec,tot,totr;
ll last[MAXN],lastr[MAXN],vis[MAXN],visr[MAXN],from[MAXN],to[MAXN];
ll useful[MAXN],inQT[MAXN],dis[MAXN];
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
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline void addEdger(ll from,ll to)
{
	edr[++totr].prev=lastr[from];
	edr[totr].to=to;
	lastr[from]=totr;
}
inline void addEdge2(ll from,ll to,ll dist)
{
	edd[++tot].prev=last[from];
	edd[tot].to=to;
	edd[tot].dist=dist;
	last[from]=tot;
}
inline void dfs(ll node)
{
	vis[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(!vis[ed[i].to])
		{
			dfs(ed[i].to);
		}
	}
}
inline void dfs2(ll node)
{
	visr[node]=1;
	for(register int i=lastr[node];i;i=edr[i].prev)
	{
		if(!visr[edr[i].to])
		{
			dfs2(edr[i].to);
		}	
	}	
} 
inline void spfa(ll source)
{
	ll top;
	q.push(source),vis[source]=1,dis[source]=0;
	while(!q.empty())
	{
		top=q.front(),q.pop(),vis[top]=0;
		for(register int i=last[top];i;i=edd[i].prev)
		{
			if(dis[edd[i].to]<dis[top]+edd[i].dist)
			{
				dis[edd[i].to]=dis[top]+edd[i].dist;
				if(!vis[edd[i].to])
				{
					q.push(edd[i].to),inQT[edd[i].to]++; 
				}
				if(inQT[edd[i].to]>nc)
				{
					puts("No");
					exit(0);
				}
			}
		}
	}
}
int main()
{
	nc=read(),ec=read();
	for(register int i=0;i<ec;i++)
	{
		from[i]=read(),to[i]=read();
		addEdge(from[i],to[i]),addEdger(to[i],from[i]);
	}
	dfs(1),dfs2(nc);
	for(register int i=1;i<=nc;i++)
	{
		useful[i]=vis[i]&visr[i];
	}
	useful[1]=useful[nc]=1;
	memset(last,tot=0,sizeof(last)),memset(vis,0,sizeof(vis));
	memset(dis,-0x3f,sizeof(dis));
	for(register int i=0;i<ec;i++)
	{
		if(useful[from[i]]&&useful[to[i]])
		{
			addEdge2(from[i],to[i],1),addEdge2(to[i],from[i],-2);
		}
	} 
	spfa(1),puts("Yes");
	for(register int i=0;i<ec;i++)
	{
		if(useful[from[i]]&useful[to[i]])
		{
			printf("%d\n",dis[to[i]]-dis[from[i]]);
			continue;
		}
		puts("1");
	}
}