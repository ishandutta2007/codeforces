// This code is written by Karry5307
#include<bits/stdc++.h>
// Definition
#define For(i,x,y) for(register int i=(x);i<(y);i++)
#define Forr(i,x,y) for(register int i=(x);i<=(y);i++)
#define Rep(i,x,y) for(register int i=(x);i>(y);i--)
#define Repp(i,x,y) for(register int i=(x);i>=(y);i--)
#define ve vector
#define iter iterator
#define pb emplace_back
#define popb pop_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define F first
#define S second
using namespace std;
// Typedefs
typedef int ll;
typedef long long int li;
typedef unsigned int ul;
typedef unsigned long long int ull;
typedef double db;
typedef long double ldb;
typedef pair<ll,ll> pii;
typedef pair<li,li> pll;
#define ll long long
const ll MAXN=1e6+51,MAXM=2.1e5+51,MOD=998244353,inf=1e12+51;
// Structures and variables
struct SegmentTree{
	ll l,r,val,tag;
};
struct Node{
	ll x,f,c;
	inline bool operator <(const Node &rhs)const
	{
		return this->x<rhs.x;
	} 
};
Node u[MAXN],v[MAXN],t[MAXN];
SegmentTree tree[MAXN<<2];
ll n,m,p,maxn,lll,res;
// Fast IO
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
} 
inline li readu()
{
    register li num=0;
    register char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return num;
} 
template<class T>
inline void writep(T x)
{
	if(x<0){return (void)putchar('-'),writep(-x);}
	if(x<10){return (void)putchar(x|48);}
	writep(x/10),putchar((x%10)|48);
}
template<class T>
inline void write(T x,char ch=' '){writep(x),putchar(ch);}
template<class T>
inline void writeln(T x){writep(x),putchar('\n');}
// chkmin and chkmax
template<class T>
inline void chkmax(T &x,const T &y){x=x>y?x:y;}
template<class T>
inline void chkmin(T &x,const T &y){x=x<y?x:y;}
// Functions
template<class T,class Compare>
inline void sort(ve<T>&v,Compare cmp=less<T>()){sort(all(v),cmp);}
template<class T>
inline void reverse(ve<T>&v){reverse(all(v));}
template<class T>
inline void clear(T *arr){memset(arr,0,sizeof(arr));}
template<class T>
inline void setInf(T *arr){memset(arr,0x3f,sizeof(arr));}
// Math funcs
inline ll qpow(ll base,ll exponent)
{
	li res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=(li)res*base%MOD;
		}
		base=(li)base*base%MOD,exponent>>=1;
	}
	return res;
}
// Functions
inline void update(ll node)
{
	tree[node].val=max(tree[node<<1].val,tree[(node<<1)|1].val);
}
inline void create(ll l,ll r,ll node)
{
	tree[node].l=l,tree[node].r=r;
	if(l==r)
	{
		tree[node].val=-inf,tree[node].tag=0;
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
		tree[node<<1].val+=tree[node].tag;
		tree[(node<<1)|1].val+=tree[node].tag;
		tree[node<<1].tag+=tree[node].tag;
		tree[(node<<1)|1].tag+=tree[node].tag;
		tree[node].tag=0;
	}
}
inline void change(ll l,ll r,ll val,ll node)
{
	if(l>tree[node].r||r<tree[node].l)
	{
		return;
	}
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		tree[node].val+=val,tree[node].tag+=val;
		return;
	}
	spread(node);
	ll mid=(tree[node].l+tree[node].r)>>1;
	if(l<=mid)
	{
		change(l,r,val,node<<1);
	}
	if(r>mid)
	{
		change(l,r,val,(node<<1)|1);
	}
	update(node);
}
inline void changePoint(ll pos,ll val,ll node)
{
	if(tree[node].l==tree[node].r)
	{
		tree[node].val=max(tree[node].val,val);
		return;
	}
	spread(node);
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
inline ll queryMax(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return tree[node].val;
	}
	spread(node);
	ll mid=(tree[node].l+tree[node].r)>>1,res=-inf;
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
	n=read(),m=read(),p=read(),res=-inf;
	for(register int i=1;i<=n;i++)
	{
		u[i].x=read(),u[i].c=read();
	}
	for(register int i=1;i<=m;i++)
	{
		v[i].f=read(),v[i].c=read(),maxn=max(maxn,v[i].f);
	}
	for(register int i=1;i<=p;i++)
	{
		t[i].x=read(),t[i].f=read(),t[i].c=read(),maxn=max(maxn,t[i].f);
	}
	sort(t+1,t+p+1),maxn++,sort(u+1,u+n+1),create(1,maxn,1);
	for(register int i=1;i<=m;i++)
	{
		changePoint(v[i].f,-v[i].c,1);
	}
	for(register int i=1;i<=n;i++)
	{
		while(lll<p&&t[lll+1].x<u[i].x)
		{
			lll++,change(t[lll].f+1,maxn,t[lll].c,1);
		}
		res=max(res,tree[1].val-u[i].c);
	}
	writeln(res);
}