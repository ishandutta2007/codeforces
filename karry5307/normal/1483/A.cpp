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
typedef long long int li;
typedef unsigned int ul;
typedef unsigned long long int ull;
typedef double db;
typedef long double ldb;
typedef pair<ll,ll> pii;
typedef pair<li,li> pll;
const ll MAXN=3e5+51,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
ll test,n,m,kk,x,lim;
ll r[MAXN],res[MAXN];
vector<ll>v[MAXN];
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
inline void solve()
{
	n=read(),m=read(),lim=(m+1)>>1;
	for(register int i=1;i<=n;i++)
	{
		r[i]=0;
	}
	for(register int i=1;i<=m;i++)
	{
		v[i].clear(),kk=read(),res[i]=0;
		for(register int j=1;j<=kk;j++)
		{
			x=read(),v[i].push_back(x);
		}
		r[v[i][0]]++;
	}
	for(register int i=1;i<=n;i++)
	{
		if(r[i]>lim)
		{
			for(register int j=1;j<=m&&r[i]>lim;j++)
			{
				v[j][0]==i&&v[j].size()>1?r[i]--,res[j]=1:1;
			}
			if(r[i]>lim)
			{
				return (void)puts("NO");
			}
		}
	}
	puts("YES");
	for(register int i=1;i<=m;i++)
	{
		printf("%d ",v[i][res[i]]);
	}
	puts("");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}