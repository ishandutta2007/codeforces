#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e5+51,inf=0x3f3f3f3f;
struct SegmentTree{
	ll l,r,mn;
};
struct Query{
	ll l,r,id;
	inline bool operator <(const Query &rhs)const
	{
		return l<rhs.l;
	} 
};
SegmentTree tree[MAXN<<2];
Query qry[MAXN];
unordered_map<ll,ll>mp;
ll n,m,l,r;
ll x[MAXN],d[MAXN],nxt[MAXN],res[MAXN];
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
	tree[node].mn=min(tree[ls].mn,tree[rs].mn);
}
inline void create(ll l,ll r,ll node)
{
	tree[node]=(SegmentTree){l,r};
	if(l==r)
	{
		return (void)(tree[node].mn=d[l]);
	}
	ll mid=(l+r)>>1;
	create(l,mid,ls),create(mid+1,r,rs),update(node);
}
inline void change(ll pos,ll val,ll node)
{
	if(tree[node].l==tree[node].r)
	{
		return (void)(tree[node].mn=val);
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	change(pos,val,pos<=mid?ls:rs),update(node);
}
inline ll query(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].mn;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	return min((l<=mid?query(l,r,ls):inf),(r>mid?query(l,r,rs):inf));
}
int main()
{
    n=read(),m=read();
    for(register int i=1;i<=n;i++)
    {
    	x[i]=read(),d[i]=mp.find(x[i])==mp.end()?inf:i-mp[x[i]];
    	mp.find(x[i])!=mp.end()?nxt[mp[x[i]]]=i:1,mp[x[i]]=i; 
	}
	create(1,n,1);
	for(register int i=1;i<=m;i++)
	{
		l=read(),r=read(),qry[i]=(Query){l,r,i};
	}
	sort(qry+1,qry+m+1),l=1;
	for(register int i=1;i<=m;i++)
	{
		while(l<qry[i].l)
		{
			change(nxt[l++],inf,1);
		}
		res[qry[i].id]=query(qry[i].l,qry[i].r,1);
	}
	for(register int i=1;i<=m;i++)
	{
		printf("%d\n",res[i]==inf?-1:res[i]);
	}
}