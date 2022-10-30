#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=5e5+51;
struct SegmentTree{
    ll l,r,gcd;
};
SegmentTree tree[MAXN<<2];
ll cnt,qcnt,op,l,r,gcds,x,y;
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
inline ll gcd(ll x,ll y)
{
    return !y?x:gcd(y,x%y);
}
inline void update(ll node)
{
    tree[node].gcd=gcd(tree[node<<1].gcd,tree[(node<<1)|1].gcd);
}
inline void create(ll l,ll r,ll node)
{
    tree[node].l=l,tree[node].r=r;
    if(l==r)
    {
        tree[node].gcd=num[l];
        return;
    }
    ll mid=(l+r)>>1;
    create(l,mid,node<<1);
    create(mid+1,r,(node<<1)|1);
    update(node);
}
inline void changePoint(ll pos,ll val,ll node)
{
    if(tree[node].l==tree[node].r)
    {
        tree[node].gcd=val;
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
inline ll queryGcd(ll l,ll r,ll gcds,ll node)
{
    if(tree[node].gcd%gcds==0)
	{
		return 1;
	}
	if(tree[node].l==tree[node].r)
	{
		return 2;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	if(l<=mid)
	{
		ll res=queryGcd(l,r,gcds,node<<1);
		if(!res)
		{
			return 0;
		}
		if(res==1)
		{
			return r>mid?queryGcd(l,r,gcds,(node<<1)|1):1;
		}
		return r>mid?(queryGcd(l,r,gcds,(node<<1)|1)==1?2:0):2;
	}
	if(r>mid)
	{
		return queryGcd(l,r,gcds,(node<<1)|1);
	}
}
int main()
{
    cnt=read();
    for(register int i=1;i<=cnt;i++)
    {
        num[i]=read();
    }
    create(1,cnt,1);
    qcnt=read();
    for(register int i=0;i<qcnt;i++)
    {
        op=read();
        if(op==1)
        {
            l=read(),r=read(),gcds=read();
            puts(!queryGcd(l,r,gcds,1)?"NO":"YES");
        }
        else
        {
            x=read(),y=read();
            changePoint(x,y,1);
        }
    }
}