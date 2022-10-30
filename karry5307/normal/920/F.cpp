#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e5+51;
struct SegmentTree{
    ll l,r,sum,maxn;
};
SegmentTree tree[MAXN<<2];
ll cnt,qcnt,op,l,r;
ll num[MAXN],d[MAXN<<2];
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
inline ll sieve(ll maxn)
{
    for(register int i=1;i<=maxn;i++)
    {
    	for(register int j=1;j<=maxn/i;j++)
		{
			d[i*j]++;	
		} 
	}
}
inline ll update(ll node)
{
    tree[node].sum=tree[node<<1].sum+tree[(node<<1)|1].sum;
    tree[node].maxn=max(tree[node<<1].maxn,tree[(node<<1)|1].maxn); 
}
inline void create(ll l,ll r,ll node)
{
    tree[node].l=l,tree[node].r=r;
    if(tree[node].l==tree[node].r)
    {
        tree[node].sum=tree[node].maxn=num[l];
        return;
    }
    ll mid=(l+r)>>1;
    create(l,mid,node<<1);
    create(mid+1,r,(node<<1)|1);
    update(node);
}
inline void change(ll l,ll r,ll node)
{
    if(tree[node].maxn<3)
    {
        return;
    }
    if(tree[node].l==tree[node].r)
    {
        tree[node].sum=tree[node].maxn=d[tree[node].sum];
        return;
    }
    ll mid=(tree[node].l+tree[node].r)>>1;
    if(l<=mid)
    {
        change(l,r,node<<1);
    }
    if(r>mid)
    {
        change(l,r,(node<<1)|1);
    }
    update(node);
}
inline ll query(ll l,ll r,ll node)
{
    if(l<=tree[node].l&&r>=tree[node].r)
    {
        return tree[node].sum;
    }
    ll mid=(tree[node].l+tree[node].r)>>1,res=0;
    if(l<=mid)
    {
        res+=query(l,r,node<<1);
    }
    if(r>mid)
    {
        res+=query(l,r,(node<<1)|1);
    }
    return res;
}
int main()
{	
    sieve(1e6);
    cnt=read(),qcnt=read();
    for(register int i=1;i<=cnt;i++)
    {
        num[i]=read();
    }
    create(1,cnt,1);
    for(register int i=0;i<qcnt;i++)
    {
        op=read(),l=read(),r=read();
        if(op==1)
        {
            change(l,r,1);  
        } 
        else
        {
            printf("%lld\n",query(l,r,1));
        }
    }
}