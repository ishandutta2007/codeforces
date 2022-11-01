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
const ll MAXN=2e4+51,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
li n,m,kk,res;
li dp[51][MAXN],prefix[51][MAXN],suffix[51][MAXN],psum[51][MAXN]; 
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
	n=read(),m=read(),kk=read();
	for(register int i=1;i<=n;i++) 
	{
		for(register int j=1;j<=m;j++)
		{
			psum[i][j]=psum[i][j-1]+read();
		}
	}
	for(register int i=kk;i<=m;i++)
	{
		dp[1][i]=psum[1][i]-psum[1][i-kk];
		prefix[1][i]=max(prefix[1][i-1],dp[1][i]+psum[2][i]-psum[2][i-kk]);
	}
	for(register int i=m;i>=kk;i--)
	{
		suffix[1][i]=max(suffix[1][i+1],dp[1][i]+psum[2][i]-psum[2][i-kk]);
	}
	for(register int i=2;i<=n;i++)
	{
		for(register int j=kk;j<=m;j++)
		{
			if(j>=kk)
			{
				dp[i][j]=max(dp[i][j],prefix[i-1][j-kk]+psum[i][j]-psum[i][j-kk]);
			}
			if(j+kk<=m)
			{
				dp[i][j]=max(dp[i][j],suffix[i-1][j+kk]+psum[i][j]-psum[i][j-kk]);
			}
			for(register int k=max(kk,j-kk+1);k<=min(j+kk-1,m);k++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][k]+psum[i][max(j,k)]-psum[i][min(j,k)-kk]);
			}
			prefix[i][j]=max(prefix[i][j-1],dp[i][j]+psum[i+1][j]-psum[i+1][j-kk]);
		}
		for(register int j=m;j>=kk;j--)
		{
			suffix[i][j]=max(suffix[i][j+1],dp[i][j]+psum[i+1][j]-psum[i+1][j-kk]);
		}
	}
	for(register int i=kk;i<=m;i++)
	{
		res=max(res,dp[n][i]);
	}
	cout<<res<<endl;
}