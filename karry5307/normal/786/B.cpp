#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e5+51;
const li inf=0x3f3f3f3f3f3f3f3f;
struct Edge{
	ll to,prev,dist;
};
struct Tuple{
	li x,y;
	inline bool operator <(const Tuple &rhs)const
	{
		return this->x>rhs.x;
	}
};
Edge ed[MAXN*20];
priority_queue<Tuple>pq;
ll cnt,nc,tot,rt,rtx,qcnt,source,op,x,y,l,r,dist;
ll last[MAXN<<2],inQueue[MAXN<<2],ls[MAXN<<2],rs[MAXN<<2];
li dis[MAXN<<2];
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
inline ll createDown(ll l,ll r)
{
	if(l==r)
	{
		return l;
	}
	ll mid=(l+r)>>1,cur=++nc;
	ls[cur]=createDown(l,mid),rs[cur]=createDown(mid+1,r);
	addEdge(cur,ls[cur],0),addEdge(cur,rs[cur],0);
	return cur;
}
inline ll createUp(ll l,ll r)
{
	if(l==r)
	{
		return l;
	}
	ll mid=(l+r)>>1,cur=++nc;
	ls[cur]=createUp(l,mid),rs[cur]=createUp(mid+1,r);
	addEdge(ls[cur],cur,0),addEdge(rs[cur],cur,0);
	return cur;
}
ll lx,rx;
inline void link(ll l,ll r,ll x,ll dist,ll node,ll type)
{
	if(lx<=l&&rx>=r)
	{
		type?addEdge(node,x,dist):addEdge(x,node,dist);
		return;
	}
	ll mid=(l+r)>>1;
	if(lx<=mid)
	{
		link(l,mid,x,dist,ls[node],type);
	}
	if(rx>mid)
	{
		link(mid+1,r,x,dist,rs[node],type);
	}
}
inline void Dijkstra(ll source)
{
	ll top;
	dis[source]=0,inQueue[source]=1,pq.push((Tuple){0,source});
	while(!pq.empty())
	{
		top=pq.top().y,pq.pop(),inQueue[top]=0;
		for(register int i=last[top];i;i=ed[i].prev)
		{
			if(dis[ed[i].to]>dis[top]+ed[i].dist)
			{
				dis[ed[i].to]=dis[top]+ed[i].dist;
				if(!inQueue[ed[i].to])
				{
					inQueue[ed[i].to]=1;
					pq.push((Tuple){dis[ed[i].to],ed[i].to});
				}
			}
		}
	}
} 
int main()
{
	cnt=nc=read(),qcnt=read(),source=read();
	rt=nc+1,createDown(1,cnt),rtx=nc+1,createUp(1,cnt);
	for(register int i=0;i<qcnt;i++)
	{
		op=read();
		if(op==1)
		{
			x=read(),y=read(),dist=read(),addEdge(x,y,dist);
			continue;
		}
		x=read(),lx=read(),rx=read(),dist=read();
		link(1,cnt,x,dist,op^3?rt:rtx,op-2);
	}
	memset(dis,0x3f,sizeof(dis)),Dijkstra(source);
	for(register int i=1;i<=cnt;i++)
	{
		printf("%lld ",dis[i]==inf?-1:dis[i]);
	}
}