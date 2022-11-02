#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e5+51;
struct SegmentTree{
	ll l,r,tag;
};
SegmentTree tree[MAXN<<2];
ll n,m;
ll l[MAXN],r[MAXN],x[MAXN];
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
inline void create(ll l,ll r,ll node)
{
	tree[node]=(SegmentTree){l,r,0};
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1;
	create(l,mid,ls),create(mid+1,r,rs);
}
inline void spread(ll node)
{
	if(tree[node].tag)
	{
		tree[ls].tag=tree[rs].tag=tree[node].tag,tree[node].tag=0;
	}
}
inline void cover(ll l,ll r,ll val,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return (void)(tree[node].tag=val);
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	l<=mid?cover(l,r,val,ls):(void)1,r>mid?cover(l,r,val,rs):(void)1;
}
inline void spreadAll(ll node)
{
	if(tree[node].l==tree[node].r)
	{
		return (void)(printf("%d ",tree[node].tag));
	}
	spread(node),spreadAll(ls),spreadAll(rs);
}
int main()
{
	n=read(),m=read(),create(1,n,1);
	for(register int i=1;i<=m;i++)
	{
		l[i]=read(),r[i]=read(),x[i]=read();
	}
	for(register int i=m;i;i--)
	{
		x[i]!=l[i]?cover(l[i],x[i]-1,x[i],1):(void)1;
		x[i]!=r[i]?cover(x[i]+1,r[i],x[i],1):(void)1;
	}
	spreadAll(1);
}