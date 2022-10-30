#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
struct Occur{
    ll num[28];
    Occur()
    {
    	memset(this->num,0,sizeof(this->num));
	}
	inline bool operator !=(const ll &rhs)const
	{
		for(register int i=1;i<=26;i++)
		{
			if(num[i]!=rhs)
			{
				return 1;
			}
		}
		return 0;
	}
	inline void clear()
	{
		memset(num,0,sizeof(num));
	}
};
struct SegmentTree{
    ll l,r;
    Occur sum,cover;
};
SegmentTree tree[MAXN<<2];
ll cnt,qcnt,l,r,x;
char str[MAXN];
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
inline Occur operator +(Occur x,Occur y)
{
    Occur res;
    for(register int i=1;i<=26;i++)
    {
        res.num[i]=x.num[i]+y.num[i];
    }
    return res;
}
inline Occur operator *(Occur x,ll y)
{
    Occur res;
    for(register int i=1;i<=26;i++)
    {
        res.num[i]=x.num[i]*y;
    }
    return res;
}
inline void update(ll node)
{
    tree[node].sum=tree[node<<1].sum+tree[(node<<1)|1].sum;
}
inline void create(ll l,ll r,ll node)
{
    tree[node].l=l,tree[node].r=r;
    if(l==r)
    {
        tree[node].sum.num[str[l-1]-'a'+1]=1;
        return;
    }
    ll mid=(l+r)>>1;
    create(l,mid,node<<1);
    create(mid+1,r,(node<<1)|1);
    update(node);
}
inline void spread(ll node)
{
	ll ls=node<<1,rs=ls|1;
	if(tree[node].cover!=0)
	{
		tree[ls].sum=tree[node].cover*(tree[ls].r-tree[ls].l+1);
		tree[rs].sum=tree[node].cover*(tree[rs].r-tree[rs].l+1);
		tree[ls].cover=tree[node].cover;
		tree[rs].cover=tree[node].cover;
		tree[node].cover.clear();
	}
}
inline void cover(ll l,ll r,Occur val,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		tree[node].sum=val*(tree[node].r-tree[node].l+1);
		tree[node].cover=val;
		return;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	if(l<=mid)
	{
		cover(l,r,val,node<<1);
	}
	if(r>mid)
	{
		cover(l,r,val,(node<<1)|1);
	}
	update(node);
}
inline Occur query(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].sum;	
	} 
	ll mid=(tree[node].l+tree[node].r)>>1;
	Occur res;
	spread(node);
	if(l<=mid)
	{
		res=res+query(l,r,node<<1);
	}
	if(r>mid)
	{
		res=res+query(l,r,(node<<1)|1);
	}
	return res;
}
inline void sorts(ll l,ll r,ll cmp)
{
	ll cur=l;
	Occur val=query(l,r,1),curr;
	if(!cmp)
	{
		for(register int i=1;i<=26;i++)
		{
			curr.num[i]=1,curr.num[i-1]=0;
			if(val.num[i])
			{
				cover(l,l+val.num[i]-1,curr,1);
				l=l+val.num[i];
			}
		}
	}
	else
	{
		for(register int i=26;i;i--)
		{
			curr.num[i]=1,curr.num[i+1]=0;
			if(val.num[i])
			{
				cover(l,l+val.num[i]-1,curr,1);
				l=l+val.num[i];
			}
		}
	}
}
inline void spreadAll(ll node)
{
	spread(node);
	if(tree[node].l==tree[node].r)
	{
		return;
	}
	spreadAll(node<<1);
	spreadAll((node<<1)|1);
	update(node);
}
inline void preorder(ll node)
{
	if(tree[node].l==tree[node].r)
	{
		for(register int i=1;i<=26;i++)
		{
			if(tree[node].sum.num[i])
			{
				putchar((char)(i+'a'-1));
				break;
			}
		}
		return;
	}
	preorder(node<<1);
	preorder((node<<1)|1);
}
int main()
{
    cnt=read(),qcnt=read();
    scanf("%s",&str);
    create(1,cnt,1);
    for(register int i=0;i<qcnt;i++)
    {
    	l=read(),r=read(),x=read();
    	sorts(l,r,!x);
	}
	spreadAll(1),preorder(1);
}