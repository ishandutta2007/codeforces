#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51,inf=0x3f3f3f3f3f3f3f3f;
struct Node{
	ll l,r,x;
	inline bool operator <(const Node &rhs)const
	{
		return this->r<rhs.r;
	}
};
struct SegmentTree{
	ll l,r,val,tag;
};
ll n,m,cur;
Node p[MAXN];
SegmentTree tree[MAXN<<2];
ll cost[MAXN],dp[MAXN];
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
inline void update(ll node)
{
	tree[node].val=max(tree[node<<1].val,tree[(node<<1)|1].val);
}
inline void create(ll l,ll r,ll node)
{
	tree[node].l=l,tree[node].r=r;
	if(l==r)
	{
		tree[node].val=0,tree[node].tag=0;
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
		tree[ls].val+=tree[node].tag,tree[ls].tag+=tree[node].tag;
		tree[rs].val+=tree[node].tag,tree[rs].tag+=tree[node].tag;
		tree[node].tag=0;
	}
}
inline void add(ll l,ll r,ll val,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		tree[node].val+=val,tree[node].tag+=val;
		return;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	if(l<=mid)
	{
		add(l,r,val,node<<1);
	}
	if(r>mid)
	{
		add(l,r,val,(node<<1)|1);
	}
	update(node);
}
inline ll queryMax(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].val;
	}
	spread(node);
	ll mid=(tree[node].l+tree[node].r)>>1,res=0;
	if(l<=mid)
	{
		res=max(res,queryMax(l,r,node<<1));
	}
	if(r>mid)
	{
		res=max(res,queryMax(l,r,(node<<1)|1));
	}
	return res;
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)	
	{
		cost[i]=read();
	}
	for(register int i=0;i<m;i++)
	{
		p[i].l=read(),p[i].r=read(),p[i].x=read();
	}
	sort(p,p+m),create(1,n+1,1);
	for(register int i=1;i<=n;i++)
	{
		while(cur<m&&p[cur].r<=i)
		{
			add(1,p[cur].l,p[cur].x,1),cur++;
		}
		add(1,i,-cost[i],1),dp[i]=queryMax(1,i,1);
		dp[i]=max(dp[i],dp[i-1]),add(i+1,i+1,dp[i],1);
	}
	printf("%lld\n",dp[n]);
}