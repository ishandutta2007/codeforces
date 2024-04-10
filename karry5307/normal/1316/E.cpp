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
	ll p[11],u;
	inline ll operator [](const ll &x)
	{
		return p[x];
	}
	inline const ll operator [](const ll &x)const
	{
		return p[x];
	}
	inline bool operator <(const Node &rhs)const
	{
		return this->u>rhs.u;
	}
};
ll n,p,kk,rr;
Node nd[MAXN];
ll prefix[MAXN],dp[MAXN][130];
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
int main()
{
	n=read(),p=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		nd[i].u=read();
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=0;j<p;j++)
		{
			nd[i].p[j]=read();
		}
	}
	sort(&nd[1],&nd[n+1]);
	for(register int i=1;i<=n;i++)
	{
		prefix[i]=prefix[i-1],prefix[i]+=nd[i].u;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=0;j<=((1<<p)-1);j++)
		{
			rr=0;
			for(register int k=0;k<=p-1;k++)
			{
				rr=rr+((j>>k)&1);
			}
			if(rr<=i)
			{
				if(kk>=i-rr&&rr+1<=i)
				{
					dp[i][j]=dp[i-1][j]+nd[i].u;
				}
				else
				{
					dp[i][j]=dp[i-1][j];
				}
			}
			for(register int k=0;k<=p-1;k++)
			{
				if((j>>k)%2==1)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j^(1<<k)]+nd[i][k]);
				}
			}
		}
	}
	printf("%lld\n",dp[n][(1<<p)-1]);
}