#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct SegmentTree{
	ll l,r,minn,tag;
};
SegmentTree tree[MAXN<<2];
ll cnt,pos,res=0x3f3f3f3f3f3f3f3f;
ll p[MAXN],x[MAXN],rp[MAXN],num[MAXN];
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
		add(l,r,val,(node<<1)|1);
	}
	update(node);
}
int main()
{
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		p[i]=read(),rp[p[i]]=i;
	}
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read(),num[i]=num[i-1]+x[i]; 
	}
	create(1,cnt-1,1),res=tree[1].minn; 
	for(register int i=1;i<=cnt;i++)
	{
		pos=rp[i];
		if(pos==1)
		{
			add(1,cnt-1,-x[pos],1);	
		}
		else
		{
			if(pos==cnt)
			{
				add(1,cnt-1,x[pos],1);
			}
			else
			{
				add(1,pos-1,x[pos],1),add(pos,cnt-1,-x[pos],1);
			}
		}
		res=min(res,tree[1].minn);
	}
	printf("%lld\n",res);
}