#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Edge{
	ll to,prev,dist;
};
struct SegmentTree{
	ll l,r,minn,tag;
};
Edge ed[MAXN];
SegmentTree tree[MAXN<<2];
ll cnt,ccnt,qcnt,x,y,tot;
ll last[MAXN],l[MAXN],num[MAXN];
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
inline void update(ll node)
{
	tree[node].minn=min(tree[node<<1].minn,tree[(node<<1)|1].minn);
}
inline void create(ll l,ll r,ll node)
{
	tree[node].l=l,tree[node].r=r;
	if(l==r)
	{
		tree[node].minn=num[l];
		return;
	}
	ll mid=(l+r)>>1;
	create(l,mid,node<<1);
	create(mid+1,r,(node<<1)|1);
	update(node);
}
inline void spread(ll node)
{
	if(tree[node].tag)
	{
		ll ls=node<<1,rs=ls|1;
		tree[ls].minn+=tree[node].tag,tree[rs].minn+=tree[node].tag;
		tree[ls].tag+=tree[node].tag,tree[rs].tag+=tree[node].tag;
		tree[node].tag=0;
	}
}
inline void add(ll l,ll r,ll val,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		tree[node].minn+=val,tree[node].tag+=val;
		return;
	}
	spread(node);
	ll mid=(tree[node].l+tree[node].r)>>1;
	if(l<=mid)
	{
		add(l,r,val,node<<1);
	}
	if(r>mid)
	{
		add(l,r,val,(node<<1)+1);
	}
	update(node);
}
int main()
{
	cnt=read(),ccnt=read(),qcnt=read();
	for(register int i=1;i<cnt;i++)
	{
		l[i]=read(),num[i+1]=read();
	}
	for(register int i=0;i<ccnt;i++)
	{
		x=read(),y=read(),addEdge(x,y,read());
	}
	create(1,cnt,1);
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=0;
		for(register int j=last[i];j;j=ed[j].prev)
		{
			add(1,ed[j].to,ed[j].dist,1);
		}
		num[i]=tree[1].minn+l[i];
	}
	memset(tree,0,sizeof(tree)),create(1,cnt,1),printf("%lld\n",tree[1].minn);
	for(register int i=0;i<qcnt;i++)
	{
		x=read(),add(x,x,(y=read())-l[x],1),l[x]=y;
		printf("%lld\n",tree[1].minn);
	}
}