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
#define lb lower_bound
#define ub upper_bound
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
ll test,x,y,z,res,lx,rx;
ll r[MAXN],g[MAXN],b[MAXN];
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
inline ll calc(ll x,ll y,ll z)
{
	return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}
inline void solve()
{
	x=read(),y=read(),z=read(),res=5e18;
	for(register int i=1;i<=x;i++)
	{
		r[i]=read();
	}
	for(register int i=1;i<=y;i++)
	{
		g[i]=read();
	}
	for(register int i=1;i<=z;i++)
	{
		b[i]=read();
	}
	sort(r+1,r+x+1),sort(g+1,g+y+1),sort(b+1,b+z+1);
	for(register int i=1;i<=x;i++)
	{
		lx=lb(g+1,g+y+1,r[i])-g;
		rx=ub(b+1,b+z+1,r[i])-b-1;
		if(lx>=1&&lx<=y&&rx>=1&&rx<=z)
		{
			res=min(res,calc(r[i],g[lx],b[rx]));
		}
		lx=ub(g+1,g+y+1,r[i])-g-1;
		rx=lb(b+1,b+z+1,r[i])-b;
		if(lx>=1&&lx<=y&&rx>=1&&rx<=z)
		{
			res=min(res,calc(r[i],g[lx],b[rx]));
		}
	}
	for(register int i=1;i<=y;i++)
	{
		lx=lb(r+1,r+x+1,g[i])-r;
		rx=ub(b+1,b+z+1,g[i])-b-1;
		if(lx>=1&&lx<=x&&rx>=1&&rx<=z)
		{
			res=min(res,calc(r[lx],g[i],b[rx]));
		}
		lx=ub(r+1,r+x+1,g[i])-r-1;
		rx=lb(b+1,b+z+1,g[i])-b;
		if(lx>=1&&lx<=x&&rx>=1&&rx<=z)
		{
			res=min(res,calc(r[lx],g[i],b[rx]));
		}
	}
	for(register int i=1;i<=z;i++)
	{
		lx=lb(g+1,g+y+1,b[i])-g;
		rx=ub(r+1,r+x+1,b[i])-r-1;
		if(lx>=1&&lx<=y&&rx>=1&&rx<=x)
		{
			res=min(res,calc(r[rx],g[lx],b[i]));
		}
		lx=ub(g+1,g+y+1,b[i])-g-1;
		rx=lb(r+1,r+x+1,b[i])-r;
		if(lx>=1&&lx<=y&&rx>=1&&rx<=x)
		{
			res=min(res,calc(r[rx],g[lx],b[i]));
		}
	}
	printf("%lld\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}