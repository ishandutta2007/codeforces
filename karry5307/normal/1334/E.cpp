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
#pragma GCC optimize("Ofast,unroll-loops")
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
const ll MAXN=1e7+51,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
map<ll,ll>res;
ll n,qcnt,u,v,d,cnt,l;
ll fact[10051],finv[10051],inv[10051];
ll p[MAXN],x[MAXN];
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
inline void setup()
{
	ll n=::n;
	for(register int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			x[++l]=i;
			while(n%i==0)
			{
				n/=i;
			}
		}
	}
	if(n!=1)
	{
		x[++l]=n;
	}
}
inline ll calc(ll n)
{
	ll u=1,t=0;
	for(register int i=1;i<=l;i++)
	{
		if(n%x[i]==0)
		{
			ll tot=0;
			while(n%x[i]==0)
			{
				tot++,t++,n/=x[i];
			}
			u=u*finv[tot]%MOD;
		}
	}
	if(n!=1)
	{
		t++;
	}
	return fact[t]*u%MOD;
}
inline void calc2(ll n)
{
	for(register int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			p[++cnt]=i;
			if(i*i!=n)
			{
				p[++cnt]=n/i;
			}
		}
	}
}
int main()
{
	n=read(),setup(),calc2(n),qcnt=read();
	fact[1]=fact[0]=finv[0]=finv[1]=inv[1]=1;
	for(register int i=2;i<=10000;i++)
	{
		fact[i]=fact[i-1]*i%MOD,inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
	for(register int i=1;i<=cnt;i++)
	{
		res[p[i]]=calc(p[i]);
	}
	for(register int i=0;i<qcnt;i++)
	{
		u=read(),v=read(),d=gcd(u,v),printf("%lld\n",res[u/d]*res[v/d]%MOD);
	}
}