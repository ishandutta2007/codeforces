#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e5+51,MOD=1e9+9,IS5=276601605,P=691504013,P2=308495997;
struct SegmentTree{
	ll l,r,sum,tag;
};
SegmentTree tree[2][MAXN<<2];
ll n,m,op,l,r,u,v;
ll x[MAXN],prefix[MAXN],pw[2][MAXN],invl[2];
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
inline ll qpow(ll base,ll exponent)
{
	ll res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=(li)res*base%MOD;
		}
		base=(li)base*base%MOD,exponent>>=1;
	}
	return res;
}
#define ls node<<1
#define rs (node<<1)|1
inline void update(ll dim,ll node)
{
	tree[dim][node].sum=(tree[dim][ls].sum+tree[dim][rs].sum)%MOD;
}
inline void create(ll l,ll r,ll dim,ll node)
{
	tree[dim][node]=(SegmentTree){l,r,0,0};
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1;
	create(l,mid,dim,ls),create(mid+1,r,dim,rs),update(dim,node);
}
inline void sprd(ll dim,ll node,ll x)
{
	ll len=tree[dim][node].r-tree[dim][node].l+1;
	ll v=(li)((li)x*pw[dim][len]%MOD-x+MOD)*invl[dim]%MOD;
	tree[dim][node].tag=(tree[dim][node].tag+x)%MOD;
	tree[dim][node].sum=(tree[dim][node].sum+v)%MOD;
}
inline void spread(ll dim,ll node)
{
	if(tree[dim][node].tag)
	{
		ll tag=tree[dim][node].tag;
		ll lenl=tree[dim][ls].r-tree[dim][ls].l+1;
		sprd(dim,ls,tag),sprd(dim,rs,(li)tag*pw[dim][lenl]%MOD);
		tree[dim][node].tag=0;
	}
}
inline void add(ll l,ll r,ll dim,ll kk,ll node)
{
	if(l<=tree[dim][node].l&&r>=tree[dim][node].r)
	{
		return sprd(dim,node,(li)kk*pw[dim][tree[dim][node].l-l]%MOD);
	}
	ll mid=(tree[dim][node].l+tree[dim][node].r)>>1;
	spread(dim,node);
	l<=mid?add(l,r,dim,kk,ls):(void)1,r>mid?add(l,r,dim,kk,rs):(void)1;
	update(dim,node); 
}
inline ll query(ll l,ll r,ll dim,ll node)
{
	if(l<=tree[dim][node].l&&r>=tree[dim][node].r)
	{
		return tree[dim][node].sum;
	}
	ll mid=(tree[dim][node].l+tree[dim][node].r)>>1;
	spread(dim,node);
	return ((l<=mid?query(l,r,dim,ls):0)+(r>mid?query(l,r,dim,rs):0))%MOD;
}
int main()
{
	n=read(),m=read(),pw[0][0]=pw[1][0]=1,invl[0]=qpow(P-1,MOD-2),invl[1]=qpow(P2-1,MOD-2);
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),prefix[i]=(prefix[i-1]+x[i])%MOD;
		pw[0][i]=(li)pw[0][i-1]*P%MOD,pw[1][i]=(li)pw[1][i-1]*P2%MOD;
	}
	create(1,n,0,1),create(1,n,1,1);
	for(register int i=0;i<m;i++)
	{
		op=read(),l=read(),r=read();
		if(op==1)
		{
			add(l,r,0,P,1),add(l,r,1,P2,1);
		}
		if(op==2)
		{
			u=(query(l,r,0,1)-query(l,r,1,1)+MOD)%MOD,v=prefix[r]-prefix[l-1];
			printf("%d\n",((v+MOD)%MOD+(li)u*IS5%MOD)%MOD);
		} 
	}
}