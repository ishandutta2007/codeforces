#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51;
struct SegmentTree{
    ll l,r,sum,maxn;
};
SegmentTree tree[MAXN<<2];
ll cnt,ccnt,op,l,r,x,y;
ll num[MAXN];
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
	tree[node].sum=tree[node<<1].sum+tree[(node<<1)|1].sum;
	tree[node].maxn=max(tree[node<<1].maxn,tree[(node<<1)|1].maxn);
}
inline void create(ll l,ll r,ll node)
{
	tree[node].l=l,tree[node].r=r;
	if(l==r)
	{
		tree[node].sum=tree[node].maxn=num[l];
		return;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	create(l,mid,node<<1);
	create(mid+1,r,(node<<1)|1);
	update(node);
}
inline void changePoint(ll pos,ll val,ll node)
{
	if(tree[node].l==tree[node].r)
	{
		tree[node].sum=tree[node].maxn=val;
		return;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	if(pos<=mid)
	{
		changePoint(pos,val,node<<1);
	}
	else
	{
		changePoint(pos,val,(node<<1)|1);
	}
	update(node);
}
inline void modulo(ll l,ll r,ll mod,ll node)
{
	if(tree[node].maxn<mod)
	{
		return;
	}
	if(tree[node].l==tree[node].r)
	{
		tree[node].sum%=mod;
		tree[node].maxn%=mod;
		return;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	if(l<=mid)
	{
		modulo(l,r,mod,node<<1);
	}
	if(r>mid)
	{
		modulo(l,r,mod,(node<<1)|1);
	}
	update(node);
}
inline ll querySum(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].sum;
	}
	ll mid=(tree[node].l+tree[node].r)>>1,res=0;
	if(l<=mid)
	{
		res+=querySum(l,r,node<<1);
	}
	if(r>mid)
	{
		res+=querySum(l,r,(node<<1)|1);
	}
	return res;
}
inline ll queryMax(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].maxn;
	}
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
    cnt=read(),ccnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();
	}
	create(1,cnt,1);
	for(register int i=0;i<ccnt;i++)
	{
		op=read();
		if(op==1)
		{
			l=read(),r=read();
			printf("%I64d\n",querySum(l,r,1));
		}
		if(op==2)
		{
			l=read(),r=read(),x=read();
			modulo(l,r,x,1);
		}
		if(op==3)
		{
			x=read(),y=read();
			changePoint(x,y,1);
		}
	}
}