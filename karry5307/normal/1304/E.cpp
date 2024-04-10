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
const ll MAXN=2e5+51,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll nc,tot,qcnt,x,y,p,q,kk,dist,d;
ll last[MAXN],depth[MAXN],anc[MAXN][19];
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
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline void dfs(ll node,ll fa)
{
	anc[node][0]=fa,depth[node]=depth[fa]+1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa)
		{
			dfs(ed[i].to,node);
		}
	}
}
inline void LCASetup()
{
	for(register int j=1;j<=18;j++)
	{
		for(register int i=1;i<=nc;i++)
		{
			anc[i][j]=anc[anc[i][j-1]][j-1];
		}
	}
}
inline ll LCA(ll x,ll y)
{
	if(depth[x]<depth[y])
	{
		swap(x,y);
	}
	for(register int i=18;i>=0;i--)
	{
		if(depth[anc[x][i]]>=depth[y])
		{
			x=anc[x][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(register int i=18;i>=0;i--)
	{
		if(anc[x][i]!=anc[y][i])
		{
			x=anc[x][i],y=anc[y][i];
		}
	}
	return anc[x][0];
}
inline ll getDist(ll x,ll y)
{
	return depth[x]+depth[y]-2*depth[LCA(x,y)];
}
int main()
{
	nc=read();
	for(register int i=0;i<nc-1;i++)
	{
		x=read(),y=read(),addEdge(x,y),addEdge(y,x);
	}
	dfs(1,0),LCASetup(),qcnt=read();
	for(register int i=0;i<qcnt;i++)
	{
		x=read(),y=read(),p=read(),q=read(),kk=read(),dist=getDist(p,q);
		if(dist<=kk&&((dist&1)==(kk&1)))
		{
			puts("YES");
			continue;
		}
		dist=getDist(p,x)+getDist(q,y)+1;
		d=getDist(x,y)+1;
		if(dist<=kk&&((dist&1)==(kk&1)))
		{
			puts("YES");
			continue;
		}
		if(d%2&&d+dist<=kk)
		{
			puts("YES");
			continue;
		}
		dist=getDist(p,y)+getDist(q,x)+1;
		if(dist<=kk&&((dist&1)==(kk&1)))
		{
			puts("YES");
			continue;
		}
		if(d%2&&d+dist<=kk)
		{
			puts("YES");
			continue;
		}
		puts("NO");
	}
}