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
const ll MAXN=551,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
ll n,m,u,v,r,res,top;
queue<ll>q;
ll d[MAXN][MAXN],pr[MAXN],gg[MAXN],inQueue[MAXN];
vector<ll>vg[MAXN];
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
	n=read(),m=read(),memset(d,0x3f,sizeof(d));
	for(register int i=1;i<=m;i++)
	{
		u=read(),v=read(),vg[u].pb(v),vg[v].pb(u),d[u][v]=d[v][u]=1;
	}
	for(register int i=1;i<=n;i++)
	{
		d[i][i]=0;
	}
	for(register int k=1;k<=n;k++)
	{
		for(register int i=1;i<=n;i++)
		{
			for(register int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			memset(gg,0,(n+5)<<2),memset(pr,0,(n+5)<<2),r=0,res=1;
			for(register int k=1;k<=n;k++)
			{
				d[i][j]==d[i][k]+d[k][j]?gg[k]=1,r++:1;
			}
			if(r!=d[i][j]+1)
			{
				putchar('0'),putchar(' ');
				continue;
			}
			while(!q.empty())
			{
				q.pop();
			}
			memset(inQueue,0,(n+5)<<2);
			for(register int k=1;k<=n;k++)
			{
				gg[k]?q.push(k),inQueue[k]=1:1;
			}
			while(!q.empty())
			{
				top=q.front(),q.pop();
				for(register int to:vg[top])
				{
					if(d[top][i]+1==d[to][i]&&d[top][j]+1==d[to][j])
					{
						pr[to]++,!inQueue[to]?q.push(to),inQueue[to]=1:1;
					}
				}
			}
			for(register int i=1;i<=n;i++)
			{
				!gg[i]?res=(li)res*pr[i]%MOD:1;
			}
			printf("%d ",res);
		}
		puts("");
	}
}