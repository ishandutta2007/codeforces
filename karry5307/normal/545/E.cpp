#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef long long int ll;
const ll MAXN=3e5+51,inf=0x3f3f3f3f3f3f3f3f;
struct Edge{
	ll to,prev,dist;
};
struct Tuple{
	ll x,y;
	inline bool operator <(const Tuple &rhs)const
	{
		return x>rhs.x;
	}
};
Edge ed[MAXN<<1];
priority_queue<Tuple>q;
ll n,m,source,tot,u,v,w,res;
ll last[MAXN],dist[MAXN],inQueue[MAXN],prv[MAXN];
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
inline void Dijkstra(ll source)
{
	ll top;
	memset(dist,0x3f,sizeof(dist)),dist[source]=0,q.push((Tuple){0,source});
	while(!q.empty())
	{
		top=q.top().y,q.pop();
		if(inQueue[top])
		{
			continue;
		}
		inQueue[top]=1;
		for(register int i=last[top];i;i=ed[i].prev)
		{
			if(dist[ed[i].to]>=dist[top]+ed[i].dist)
			{
				dist[ed[i].to]=dist[top]+ed[i].dist;
				prv[ed[i].to]=i,q.push((Tuple){dist[ed[i].to],ed[i].to});
			}
		}
	}
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=m;i++)
	{
		u=read(),v=read(),w=read();
		addEdge(u,v,w),addEdge(v,u,w);
	}
	Dijkstra(source=read());
	for(register int i=1;i<=n;i++)
	{
		res+=ed[prv[i]].dist;
	}
	printf("%lld\n",res);
	for(register int i=1;i<=n;i++)
	{
		i!=source?printf("%lld ",(prv[i]+1)>>1):1;
	}
}