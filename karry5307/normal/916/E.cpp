#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e5+51;
struct SegmentTree{
	ll l,r;
	li sm,tag;
};
struct Edge{
	ll to,prev;
};
SegmentTree tree[MAXN<<2];
Edge ed[MAXN<<1];
ll n,qcnt,tot,totd,rt,op,u,v,w,r1,r2,r3;
ll last[MAXN],fa[MAXN],depth[MAXN],sz[MAXN],hv[MAXN],dfn[MAXN];
ll top[MAXN],val[MAXN],x[MAXN];
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
inline void write(li x)
{
	ll st[64];
	ll tp=0;
	if(x==0)
	{
		return (void)putchar('0');
	}
	x<0?putchar('-'),x=-x:1;
	while(x)
	{
		st[++tp]=x%10,x/=10;
	}
	while(tp)
	{
		putchar(st[tp--]+'0');
	}
}
inline void addEdge(ll u,ll v)
{
	ed[++tot]=(Edge){v,last[u]},last[u]=tot;
}
inline void dfs(ll node,ll f)
{
	ll mx=-1;
	depth[node]=depth[fa[node]=f]+1,sz[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=f)
		{
			dfs(ed[i].to,node),sz[node]+=sz[ed[i].to];
			sz[ed[i].to]>mx?mx=sz[hv[node]=ed[i].to]:1;
		}
	}
}
inline void dfs2(ll node,ll link)
{
	ll to;
	x[dfn[node]=++totd]=val[node],top[node]=link;
	if(!hv[node])
	{
		return;
	}
	dfs2(hv[node],link);
	for(register int i=last[node];i;i=ed[i].prev)
	{
		(to=ed[i].to)!=fa[node]&&to!=hv[node]?dfs2(to,to):(void)1;
	}
}
inline ll LCA(ll x,ll y)
{
	while(top[x]!=top[y])
	{
		depth[top[x]]<depth[top[y]]?swap(x,y):(void)1,x=fa[top[x]];
	}
	return depth[x]<depth[y]?x:y;
}
#define ls node<<1
#define rs (node<<1)|1
inline void update(ll node)
{
	tree[node].sm=tree[ls].sm+tree[rs].sm;
}
inline void create(ll l,ll r,ll node)
{
	tree[node]=(SegmentTree){l,r,0,0};
	if(l==r)
	{
		return (void)(tree[node].sm=x[l]);
	}
	ll mid=(l+r)>>1;
	create(l,mid,ls),create(mid+1,r,rs),update(node);
}
inline void spread(ll node)
{
	li tag,lenl,lenr;
	if(tag=tree[node].tag)
	{
		lenl=tree[ls].r-tree[ls].l+1,lenr=tree[rs].r-tree[rs].l+1;
		tree[ls].sm+=tag*lenl,tree[rs].sm+=tag*lenr;
		tree[ls].tag+=tag,tree[rs].tag+=tag,tree[node].tag=0;
	}
}
inline void add(ll l,ll r,li val,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		ll len=(tree[node].r-tree[node].l+1);
		return (void)(tree[node].sm+=len*val,tree[node].tag+=val);
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	l<=mid?add(l,r,val,ls):(void)1,r>mid?add(l,r,val,rs):(void)1,update(node);
}
inline li query(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].sm;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	return (l<=mid?query(l,r,ls):0)+(r>mid?query(l,r,rs):0);
}
inline ll jump(ll x,ll y)
{
	while(top[x]!=top[y])
	{
		if(fa[top[x]]==y)
		{
			return top[x];
		}
		x=fa[top[x]];
	}
	return hv[y];
}
inline void add(ll x,ll val)
{
	ll d;
	if(x==rt)
	{
		return (void)add(1,n,val,1);
	}
	if(dfn[x]<=dfn[rt]&&dfn[x]+sz[x]-1>=dfn[rt]+sz[rt]-1)
	{
		d=jump(rt,x),add(1,n,val,1);
		return add(dfn[d],dfn[d]+sz[d]-1,-val,1);
	}
	add(dfn[x],dfn[x]+sz[x]-1,val,1);
}
inline li query(ll x)
{
	li d,res=0;
	if(x==rt)
	{
		return query(1,n,1);
	}
	if(dfn[x]<=dfn[rt]&&dfn[x]+sz[x]-1>=dfn[rt]+sz[rt]-1)
	{
		d=jump(rt,x),res=query(1,n,1);
		return res-query(dfn[d],dfn[d]+sz[d]-1,1);
	}
	return query(dfn[x],dfn[x]+sz[x]-1,1);
}
int main()
{
	n=read(),qcnt=read(),rt=1;
	for(register int i=1;i<=n;i++)
	{
		val[i]=read();
	}
	for(register int i=1;i<=n-1;i++)
	{
		u=read(),v=read(),addEdge(u,v),addEdge(v,u);
	}
	dfs(1,0),dfs2(1,1),create(1,n,1);
	for(register int i=1;i<=qcnt;i++)
	{
		op=read();
		if(op==1)
		{
			rt=read();
		}
		if(op==2)
		{
			u=read(),v=read(),w=read(),r1=LCA(u,rt),r2=LCA(v,rt),r3=LCA(u,v);
			depth[r1]<depth[r2]?swap(r1,r2):(void)1;
			depth[r1]<depth[r3]?swap(r1,r3):(void)1;
			add(r1,w);
		}
		if(op==3)
		{
			write(query(read())),putchar('\n');
		}
	}
}