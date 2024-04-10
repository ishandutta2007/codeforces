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
const ll MAXN=2e5+51,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
struct Node{
	ll p,v;
	inline bool operator <(const Node &rhs)const
	{
		return this->p<rhs.p;
	}
};
struct SegmentTree{
	ll ls,rs,p,q;
};
Node nd[MAXN];
SegmentTree tree[MAXN*40];
ll cnt,minn,maxn,rt,cur,res,r1,r2;
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
inline void change(ll l,ll r,ll pos,ll val,ll val2,ll &rt)
{
	if(!rt)
	{
		rt=++cur;
	}
	tree[rt].p+=val,tree[rt].q+=val2;
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1;
	if(pos<=mid)
	{
		change(l,mid,pos,val,val2,tree[rt].ls);
	}
	if(pos>mid)
	{
		change(mid+1,r,pos,val,val2,tree[rt].rs);
	}
}
inline ll query(ll l,ll r,ll ql,ll qr,ll rt)
{
	if(!rt)
	{
		return 0;
	}
	if(ql<=l&&r<=qr)
	{
		return tree[rt].p;
	}
	ll mid=(l+r)>>1,res=0;
	if(ql<=mid)
	{
		res+=query(l,mid,ql,qr,tree[rt].ls);
	}
	if(qr>mid)
	{
		res+=query(mid+1,r,ql,qr,tree[rt].rs);
	}
	return res;
}
inline ll queryVal2(ll l,ll r,ll ql,ll qr,ll rt)
{
	if(!rt)
	{
		return 0;
	}
	if(ql<=l&&r<=qr)
	{
		return tree[rt].q;
	}
	ll mid=(l+r)>>1,res=0;
	if(ql<=mid)
	{
		res+=queryVal2(l,mid,ql,qr,tree[rt].ls);
	}
	if(qr>mid)
	{
		res+=queryVal2(mid+1,r,ql,qr,tree[rt].rs);
	}
	return res;
}
int main()
{
	cnt=read(),minn=0x3f3f3f3f,maxn=-0x3f3f3f3f;
	for(register int i=1;i<=cnt;i++)
	{
		nd[i].p=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		nd[i].v=read(),minn=min(minn,nd[i].v),maxn=max(maxn,nd[i].v);
	}
	sort(nd+1,nd+cnt+1);
	for(register int i=1;i<=cnt;i++)
	{
		r1=query(minn,maxn,minn,nd[i].v,rt);
		r2=queryVal2(minn,maxn,minn,nd[i].v,rt);
		res+=r1*nd[i].p-r2;
		change(minn,maxn,nd[i].v,1,nd[i].p,rt);
	} 
	write(res);
}