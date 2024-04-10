#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
struct BIT{
	ll size;
	ll num[MAXN];
	inline ll lowbit(ll x)
	{
		return x&-x;
	}
	inline void add(ll pos,ll val)
	{
		for(;pos<=size;pos+=lowbit(pos))
		{
			num[pos]+=val;
		}
	}
	inline ll queryPrefix(ll pos)
	{
		ll res=0;
		for(;pos;pos-=lowbit(pos))
		{
			res+=num[pos];
		}
		return res;
	}
};
struct SegmentTree{
	ll l,r,size;
};
BIT bit,bit2;
SegmentTree tree[MAXN<<2];
ll cnt,num;
ll perm[MAXN];
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
	tree[node].size=tree[node<<1].size+tree[(node<<1)|1].size;
}
inline void create(ll l,ll r,ll node)
{
	tree[node].l=l,tree[node].r=r;
	if(l==r)
	{
		tree[node].size=1;
		return;
	}
	ll mid=(l+r)>>1;
	create(l,mid,node<<1);
	create(mid+1,r,(node<<1)|1);
	update(node);
}
inline ll findVal(ll rk,ll node)
{
	if(tree[node].l==tree[node].r)
	{
		tree[node].size=0;
		return tree[node].l;	
	}	
	ll res=0;
	if(rk<=tree[node<<1].size)
	{
		res=findVal(rk,node<<1);
	}
	else
	{
		res=findVal(rk-tree[node<<1].size,(node<<1)|1);
	} 
	update(node);
	return res;
}
int main()
{
	bit.size=bit2.size=cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		num=read();
		perm[i]=num-bit.queryPrefix(num),bit.add(num+1,1);
	}
	for(register int i=1;i<=cnt;i++)
	{
		num=read();
		perm[i]+=num-bit2.queryPrefix(num),bit2.add(num+1,1);
	}
	for(register int i=cnt,j=0;i;i--,j++)
	{
		perm[i-1]+=perm[i]/(j+1),perm[i]%=(j+1);
	}
	create(1,cnt,1);
	for(register int i=1;i<=cnt;i++)
	{
		printf("%d ",findVal(perm[i]+1,1)-1);
	} 
} 
//