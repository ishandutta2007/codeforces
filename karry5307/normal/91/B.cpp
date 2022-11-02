#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,inf=0x3f3f3f3f; 
struct SegmentTree{
	ll l,r,mx;
};
SegmentTree tree[MAXN<<2];
set<ll>st;
map<ll,ll>mp;
ll n,tot,v;
ll x[MAXN],res[MAXN];
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
	tree[node].mx=max(tree[ls].mx,tree[rs].mx);
}
inline void create(ll l,ll r,ll node)
{
	tree[node]=(SegmentTree){l,r,-inf};
	if(l==r)
	{
		return;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	create(l,mid,ls),create(mid+1,r,rs);
}
inline void change(ll pos,ll val,ll node)
{
	if(tree[node].l==tree[node].r)
	{
		return (void)(tree[node].mx=max(tree[node].mx,val));
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	change(pos,val,pos<=mid?ls:rs),update(node);
}
inline ll query(ll l,ll r,ll node)
{
	if(l>r)
	{
		return -inf;
	}
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].mx;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	return max(l<=mid?query(l,r,ls):-inf,r>mid?query(l,r,rs):-inf);
}
#undef ls
#undef rs
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		st.insert(x[i]=read());
	}
	for(register set<ll>::iterator it=st.begin();it!=st.end();++it)
	{
		mp[*it]=++tot;
	}
	create(1,tot,1);
	for(register int i=n;i;i--)
	{
		v=query(1,mp[x[i]]-1,1),change(mp[x[i]],i,1);
		res[i]=(v==-inf?-1:v-i-1);
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",res[i]); 
	}
}