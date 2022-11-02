#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,inf=0x3f3f3f3f; 
struct SegmentTree{
	ll l,r,mn,mn2;
};
SegmentTree tree[MAXN<<2];
ll n,res=-inf;
ll h[MAXN];
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
	tree[node].mn2=min(tree[ls].mn2,tree[rs].mn2);
}
inline void create(ll l,ll r,ll node)
{
	tree[node]=(SegmentTree){l,r,0,0};
	if(l==r)
	{
		return (void)(tree[node].mn=h[l]-l,tree[node].mn2=h[l]+l);
	}
	ll mid=(l+r)>>1;
	create(l,mid,ls),create(mid+1,r,rs),update(node);
}
inline ll query(ll l,ll r,ll node)
{
	if(l>r)
	{
		return inf;
	}
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].mn;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	return min(l<=mid?query(l,r,ls):inf,r>mid?query(l,r,rs):inf);
}
inline ll query2(ll l,ll r,ll node)
{
	if(l>r)
	{
		return inf;
	}
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].mn2;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	return min(l<=mid?query2(l,r,ls):inf,r>mid?query2(l,r,rs):inf);
}
#undef ls
#undef rs
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		h[i]=read();
	}
	create(0,n+1,1);
	for(register int i=0;i<=n+1;i++)
	{
		res=max(res,min(query(0,i,1)+i,query2(i,n+1,1)-i));
	}
	printf("%d\n",res);
}