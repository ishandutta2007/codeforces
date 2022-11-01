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
const ll MAXN=1e3+51,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
struct Tuple{
	ll x,y,u,v;
};
ll n,flg;
Tuple top,nxt;
ll x[MAXN][MAXN],y[MAXN][MAXN],vis[MAXN][MAXN];
ll vx[4]={0,-1,0,1},vy[4]={-1,0,1,0};
char ch[4]={'L','U','R','D'};
queue<Tuple>q;
char res[MAXN][MAXN];
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
inline ll dfs(ll xu,ll yu,ll dir)
{
	vis[xu][yu]=1,res[xu][yu]=ch[(dir+2)%4];
	ll sz=1;
	for(register int i=0;i<4;i++)
	{
		if(x[xu+vx[i]][yu+vy[i]]==-1&&!vis[xu+vx[i]][yu+vy[i]])
		{
			sz+=dfs(xu+vx[i],yu+vy[i],i);
		}
	}
	return sz;
}
inline void dfs2(ll xu,ll yu,ll xx,ll yy,ll dir)
{
	vis[xu][yu]=1;
	if(xx!=xu||yy!=yu)
	{
		res[xu][yu]=ch[(dir+2)%4];
	}
	for(register int i=0;i<4;i++)
	{
		if(x[xu+vx[i]][yu+vy[i]]==xx&&y[xu+vx[i]][yu+vy[i]]==yy&&!vis[xu+vx[i]][yu+vy[i]])
		{
			dfs2(xu+vx[i],yu+vy[i],xx,yy,i);
		}
	}
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			x[i][j]=read(),y[i][j]=read();
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			if(x[i][j]==-1&&!vis[i][j])
			{
				if(dfs(i,j,0)<2)
				{
					return puts("INVALID"),0;
				}
			}
			for(register int k=0;k<4;k++)
			{
				if(x[i+vx[k]][j+vy[k]]==-1)
				{
					res[i][j]=ch[k];
					break;
				}
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			if(x[i][j]==i&&y[i][j]==j)
			{
				res[i][j]='X';
				dfs2(i,j,i,j,0);
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			if(!vis[i][j])
			{
				return puts("INVALID"),0;
			}
		}
	}
	puts("VALID");
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			cout<<res[i][j];
		}
		puts("");
	}
}