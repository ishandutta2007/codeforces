#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct SegmentTree{
    ll l,r,minn,tag;
};
SegmentTree tree[MAXN<<2];
ll cnt,qcnt,space,l,r,x;
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
    space=ch==' ';
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
        tree[node<<1].minn+=tree[node].tag;
        tree[(node<<1)|1].minn+=tree[node].tag;
        tree[node<<1].tag+=tree[node].tag;
        tree[(node<<1)|1].tag+=tree[node].tag;
        tree[node].tag=0;
    }
}
inline void add(ll l,ll r,ll sum,ll node)
{
    if(l<=tree[node].l&&r>=tree[node].r)
    {
        tree[node].minn+=sum;
        tree[node].tag+=sum;
        return;
    }
    spread(node);
    ll mid=(tree[node].l+tree[node].r)>>1;
    if(l<=mid)
    {
        add(l,r,sum,node<<1);
    }
    if(r>mid)
    {
        add(l,r,sum,(node<<1)|1);
    }
    update(node);
}
inline ll queryMin(ll l,ll r,ll node)
{
    if(l<=tree[node].l&&r>=tree[node].r)
    {
        return tree[node].minn;
    }
    spread(node);
    ll mid=(tree[node].l+tree[node].r)>>1,res=0x7fffffffffffffff;
    if(l<=mid)
    {
        res=min(res,queryMin(l,r,node<<1));
    }
    if(r>mid)
    {
        res=min(res,queryMin(l,r,(node<<1)|1));
    }
    return res;
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
        l=read()+1,r=read()+1;
        if(space)
        {
            x=read();
            if(l<=r)
            {
                add(l,r,x,1);
            }
            else
            {
                add(l,cnt,x,1),add(1,r,x,1);
            }
        }
        else
        {
            if(l<=r)
            {
                printf("%I64d\n",queryMin(l,r,1));
            }
            else
            {
                printf("%I64d\n",min(queryMin(l,cnt,1),queryMin(1,r,1)));
            }
        }
    }
}