#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef long double db;
const ll MAXN=2e5+51;
struct SegmentTree{
	ll l,r;
	db val,prod;
};
SegmentTree tree[MAXN<<2];
ll n,m,op,l,r,x,y;
ll u[MAXN],v[MAXN];
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
inline SegmentTree operator +(SegmentTree x,SegmentTree y)
{
	return {x.l,y.r,x.val+x.prod*(y.val-1),x.prod*y.prod};
}
inline void update(ll node)
{
	tree[node].val=tree[ls].val+tree[ls].prod*(tree[rs].val-1);
	tree[node].prod=tree[ls].prod*tree[rs].prod;
}
inline void create(ll l,ll r,ll node)
{
	tree[node]=(SegmentTree){l,r};
	if(l==r)
	{
		return (void)(tree[node].val=1+(tree[node].prod=(db)v[l]/u[l]));
	}
	ll mid=(l+r)>>1;
	create(l,mid,ls),create(mid+1,r,rs),update(node);
}
inline void change(ll pos,ll u,ll v,ll node)
{
	if(tree[node].l==tree[node].r)
	{
		return (void)(tree[node].val=1+(tree[node].prod=(db)u/v));
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	change(pos,u,v,pos<=mid?ls:rs),update(node);
}
inline SegmentTree query(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node];
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	if(r<=mid)
	{
		return query(l,r,ls);
	}
	if(l>mid)
	{
		return query(l,r,rs);
	}
	return query(l,r,ls)+query(l,r,rs);	
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		u[i]=read(),v[i]=read()-u[i];
	}
	create(1,n,1); 
	for(register int i=1;i<=m;i++)
	{
		op=read(),l=read();
		if(op==1)
		{
			y=read(),x=read()-y,change(l,x,y,1);
		}
		if(op==2)
		{
			r=read();
			cout<<fixed<<setprecision(10)<<(db)1/query(l,r,1).val<<endl;
		}
	}
}