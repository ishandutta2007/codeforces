#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct SegmentTree{
	ll l,r,mn,sum,tag;
};
SegmentTree tree[MAXN<<2];
ll n,m,op,u,v;
ll x[MAXN];
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
#define ls node<<1
#define rs (node<<1)|1
inline void update(ll node)
{
	tree[node].mn=min(tree[ls].mn,tree[rs].mn);
	tree[node].sum=tree[ls].sum+tree[rs].sum;
}
inline void create(ll l,ll r,ll node)
{
	tree[node]=(SegmentTree){l,r,0,0,0};
	if(l==r)
	{
		return (void)(tree[node].sum=tree[node].mn=x[l]);
	}
	ll mid=(l+r)>>1;
	create(l,mid,ls),create(mid+1,r,rs),update(node);
}
inline void spread(ll node)
{
	if(tree[node].tag)
	{
		ll lenl=tree[ls].r-tree[ls].l+1,lenr=tree[rs].r-tree[rs].l+1;
		ll tag=tree[node].tag;
		tree[ls].mn=tag,tree[rs].mn=tag,tree[ls].tag=tag,tree[rs].tag=tag;
		tree[ls].sum=tag*lenl,tree[rs].sum=tag*lenr,tree[node].tag=0;
	}
}
inline void cover(ll l,ll r,ll val,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		tree[node].sum=val*(tree[node].r-tree[node].l+1);
		return (void)(tree[node].tag=tree[node].mn=val);
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	l<=mid?cover(l,r,val,ls):(void)1,r>mid?cover(l,r,val,rs):(void)1;
	update(node);
}
inline ll query(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].sum;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	return (l<=mid?query(l,r,ls):0)+(r>mid?query(l,r,rs):0);
}
inline ll lb(ll val,ll node)
{
	if(tree[node].l==tree[node].r)
	{
		return tree[node].l;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	return lb(val,tree[ls].mn>val?rs:ls);
}
inline ll query(ll &val,ll node)
{
	if(tree[node].sum<=val)
	{
		return val-=tree[node].sum,tree[node].r-tree[node].l+1;
	}
	if(tree[node].l==tree[node].r)
	{
		return 0;
	}
	spread(node);
	ll lenl=tree[node].r-tree[node].l+1,res=0;
	tree[ls].mn<=val?res+=query(val,ls):1;
	tree[rs].mn<=val?res+=query(val,rs):1;
	return res;
}
inline void disp(ll node)
{
	if(tree[node].l==tree[node].r)
	{
		return (void)(printf("%d ",tree[node].sum));
	}
	spread(node),disp(ls),disp(rs);
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	create(1,n,1);
	for(register int i=0;i<m;i++)
	{
		op=read(),u=read(),v=read();
		if(op==1)
		{
			cover(lb(v,1),u,v,1);
		}
		if(op==2)
		{
			v+=u>1?query(1,u-1,1):0,printf("%d\n",query(v,1)-u+1);
		}
	}
}