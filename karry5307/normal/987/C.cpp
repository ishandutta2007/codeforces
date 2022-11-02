#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,inf=0x3f3f3f3f;
struct SegmentTree{
	ll l,r,mn;
};
SegmentTree tree[4][MAXN<<2];
set<ll>st;
map<ll,ll>mp;
ll n,tot,res;
ll s[MAXN],c[MAXN];
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
inline void update(ll dim,ll node)
{
	tree[dim][node].mn=min(tree[dim][ls].mn,tree[dim][rs].mn);
}
inline void create(ll l,ll r,ll dim,ll node)
{
	tree[dim][node]=(SegmentTree){l,r,inf};
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1;
	create(l,mid,dim,ls),create(mid+1,r,dim,rs),update(dim,node);
}
inline void change(ll pos,ll val,ll dim,ll node)
{
	if(tree[dim][node].l==tree[dim][node].r)
	{
		return (void)(tree[dim][node].mn=min(tree[dim][node].mn,val));
	}
	ll mid=(tree[dim][node].l+tree[dim][node].r)>>1;
	change(pos,val,dim,pos<=mid?ls:rs),update(dim,node);
}
inline ll query(ll l,ll r,ll dim,ll node)
{
	if(l<=tree[dim][node].l&&r>=tree[dim][node].r)
	{
		return tree[dim][node].mn;
	}
	ll mid=(tree[dim][node].l+tree[dim][node].r)>>1;
	return min(l<=mid?query(l,r,dim,ls):inf,r>mid?query(l,r,dim,rs):inf);
}
inline void calc(ll dim,ll node)
{
	if(tree[dim][node].l==tree[dim][node].r)
	{
		return (void)printf("%d ",tree[dim][node].mn);
	}
	calc(dim,ls),calc(dim,rs);
}
inline void get(ll node)
{
	if(tree[3][node].l==tree[3][node].r)
	{
		return (void)(res=min(res,tree[3][node].mn));
	}
	get(ls),get(rs); 
}
#undef ls
#undef rs
int main()
{
	n=read(),res=inf;
	for(register int i=1;i<=n;i++)
	{
		st.insert(s[i]=read());
	}
	for(register int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	for(register set<ll>::iterator it=st.begin();it!=st.end();++it)
	{
		mp[*it]=++tot;
	}
	for(register int i=0;i<=3;i++)
	{
		create(0,n,i,1);
	}
	change(0,0,0,1);
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=3;j++)
		{
			change(mp[s[i]],query(0,mp[s[i]]-1,j-1,1)+c[i],j,1);
		}
	}
	get(1),printf("%d\n",res==inf?-1:res);
}