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
struct BIT{
	ll sz;
	ll num[MAXN];
	inline void add(ll pos,ll val)
	{
		for(;pos<=sz;pos+=pos&-pos)
		{
			num[pos]+=val;
		}
	}
	inline ll query(ll pos)
	{
		ll res=0;
		for(;pos;pos-=pos&-pos)
		{
			res+=num[pos];
		}
		return res;
	}
}; 
BIT bit;
ll n,kk,flg,tot,sum,wyx,wyxkk,sm1,sm2,res;
ll x[MAXN],t[MAXN],num[MAXN],p[MAXN],c[MAXN];
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
int main()
{
	n=bit.sz=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		sum+=(x[i]=read());
	}
	sort(x+1,x+n+1);
	for(register int i=1;i<=n;i++)
	{
		x[i]!=x[i-1]?(p[i]=++tot,num[tot]=i):p[i]=tot;
		bit.add(p[i],x[i]),t[tot]++;
	}
	num[++tot]=n+1,res=1e18;
	for(register int i=1;i<=n;i++)
	{
		if(p[i]!=p[i-1])
		{
			wyx=num[p[i]]-1,wyxkk=n-num[p[i]+1]+1;
			sm1=(x[i]-1)*wyx-bit.query(p[i]-1);
			sm2=sum-bit.query(p[i])-(x[i]+1)*wyxkk;
			if(t[p[i]]>=kk)
			{
				return puts("0"),0;
			}
			flg=1;
			if(wyx+t[p[i]]>=kk)
			{
				res=min(res,sm1+kk-t[p[i]]),flg=0;
			}
			if(wyxkk+t[p[i]]>=kk)
			{
				res=min(res,sm2+kk-t[p[i]]),flg=0;
			}
			if(flg)
			{
				res=min(res,sm1+sm2+kk-t[p[i]]);
			}
		}
	}
	printf("%lld\n",res);
}