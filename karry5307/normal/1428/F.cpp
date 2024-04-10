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
#define PY return (void)puts("Yes")
#define PN return (void)puts("No")
#define P0 return (void)puts("0")
#define P1 return (void)puts("-1")
using namespace std;
// Typedefs
typedef int ll;
#define ll long long
typedef long long int li;
typedef unsigned int ul;
typedef unsigned long long int ull;
typedef double db;
typedef long double ldb;
typedef pair<ll,ll> pii;
typedef pair<li,li> pll;
const ll MAXN=5e5+51,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
struct SegmentTree{
	ll l,r,sum,mx,tag,tag2;
};
SegmentTree tree[MAXN<<2];
ll n,res,lst,cur;
ll x[MAXN];
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
inline ll gcd(ll x,ll y)
{
	return !y?x:gcd(y,x%y);
}
inline li lcm(ll x,ll y)
{
	return x/gcd(x,y)*y;
}
// Functions
#define ls node<<1
#define rs (node<<1)|1
inline void update(ll node)
{
	tree[node].sum=tree[ls].sum+tree[rs].sum;
	tree[node].mx=max(tree[ls].mx,tree[rs].mx);
}
inline void create(ll l,ll r,ll node)
{
	tree[node]=(SegmentTree){l,r,0,0,0,0};
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1;
	create(l,mid,ls),create(mid+1,r,rs),update(node);
}
inline void spread(ll node)
{
	ll lenl=tree[ls].r-tree[ls].l+1,lenr=tree[rs].r-tree[rs].l+1;
	if(tree[node].tag2)
	{
		ll tag=tree[node].tag2;
		tree[ls].sum=lenl*tree[node].tag2,tree[rs].sum=tree[node].tag2;
		tree[ls].tag=tree[rs].tag=0,tree[ls].mx=tree[rs].mx=tag;
		tree[ls].tag2=tree[rs].tag2=tree[node].tag2,tree[node].tag2=0;		
	}
	if(tree[node].tag)
	{
		ll tag=tree[node].tag;
		tree[ls].sum+=lenl*tree[node].tag,tree[rs].sum+=tree[node].tag;
		tree[ls].tag+=tree[node].tag,tree[rs].tag+=tree[node].tag;
		tree[node].tag=0,tree[ls].mx+=tag,tree[rs].mx+=tag;
	}
}
inline void add(ll l,ll r,ll val,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		ll len=tree[node].r-tree[node].l+1;
		tree[node].mx+=val;
		return (void)(tree[node].sum+=len*val,tree[node].tag+=val);
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	l<=mid?add(l,r,val,ls):(void)1,r>mid?add(l,r,val,rs):(void)1,update(node);
}
inline void cover(ll l,ll r,ll val,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		ll len=tree[node].r-tree[node].l+1;
		tree[node].tag=0,tree[node].sum=len*val,tree[node].mx=val;
		return (void)(tree[node].tag2=val);
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	spread(node);
	l<=mid?cover(l,r,val,ls):(void)1,r>mid?cover(l,r,val,rs):(void)1;
	update(node);
}
inline ll query2(ll rk,ll node)
{
	if(tree[node].l==tree[node].r)
	{
		return tree[node].l;
	}
	spread(node);
	return query2(rk,tree[rs].mx>=rk?rs:ls);
}
int main()
{
	n=read(),create(1,n,1);
	for(register int i=1;i<=n;i++)
	{
		scanf("%1lld",&x[i]);
	}
	for(register int i=1;i<=n;i++)
	{
		if(x[i]==1)
		{
			if(!lst)
			{
				lst=i;
			}
			cur=query2(i-lst+1,1),add(lst,i,1,1);
			if(cur<lst)
			{
				cover(cur,lst-1,i-lst+1,1);
			}
		}
		else
		{
			lst=0;
		}
		res+=tree[1].sum;
	}
	printf("%lld\n",res);
}