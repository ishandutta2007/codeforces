#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51;
struct SegmentTree{
	ll l,r,andv,tag;
};
SegmentTree tree[MAXN<<2];
ll cnt,ccnt;
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
inline void update(ll node)
{
	tree[node].andv=tree[node<<1].andv&tree[(node<<1)|1].andv;
}
inline void create(ll l,ll r,ll node)
{
	tree[node].l=l,tree[node].r=r;
	if(l==r)
	{
		tree[node].andv=0;
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
		tree[node<<1].andv|=tree[node].tag;
		tree[(node<<1)|1].andv|=tree[node].tag;
		tree[node<<1].tag|=tree[node].tag;
		tree[(node<<1)|1].tag|=tree[node].tag;
		tree[node].tag=0;
	}
}
inline void orz(ll l,ll r,ll val,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		tree[node].andv|=val;
		tree[node].tag|=val;
		return;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	if(l<=mid)
	{
		orz(l,r,val,node<<1);
	}
	if(r>mid)
	{
		orz(l,r,val,(node<<1)|1);
	}
	update(node);
}
inline ll queryAnd(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].andv;
	}
	ll mid=(tree[node].l+tree[node].r)>>1,res=1073741823;
	spread(node);
	if(l<=mid)
	{
		res&=queryAnd(l,r,node<<1);
	}
	if(r>mid)
	{
		res&=queryAnd(l,r,(node<<1)|1);
	}
	return res;
}
int main()
{
	cnt=read(),ccnt=read();
	create(1,cnt,1);
	for(register int i=0;i<ccnt;i++)
	{
		l[i]=read(),r[i]=read(),x[i]=read();
		orz(l[i],r[i],x[i],1);
	}
	for(register int i=0;i<ccnt;i++)
	{
		if(queryAnd(l[i],r[i],1)!=x[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(register int i=1;i<=cnt;i++)
	{
		printf("%d ",queryAnd(i,i,1));
	}
}