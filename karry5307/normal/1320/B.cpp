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
struct Tuple{
	ll x,y;
	inline bool operator <(const Tuple &rhs)const
	{
		return this->x>rhs.x;
	}
};
Edge ed[MAXN<<1];
queue<Tuple>q;
map<ll,ll>mp[MAXN];
ll nc,ec,cnt,tot,from,to,mi,ma;
ll last[MAXN],x[MAXN],dist[MAXN],inQueue[MAXN];
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
inline void Dijkstra(ll source)
{
	ll top;
	memset(dist,0x3f,sizeof(dist)),dist[source]=0,inQueue[source]=1;
	q.push((Tuple){0,source});
	while(!q.empty())
	{
		top=q.front().y,q.pop(),inQueue[top]=0;
		for(register int i=last[top];i;i=ed[i].prev)
		{
			if(dist[ed[i].to]>dist[top]+1)
			{
				dist[ed[i].to]=dist[top]+1;
				if(!inQueue[ed[i].to])
				{
					q.push((Tuple){dist[ed[i].to],ed[i].to});
					inQueue[ed[i].to]=1;
				}
			}
		}
	}
}
int main()
{
	nc=read(),ec=read();
	for(register int i=0;i<ec;i++)
	{
		from=read(),to=read(),addEdge(to,from);
	}
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read();
	}
	Dijkstra(x[cnt]);
	for(register int i=1;i<=nc;i++)
	{
		for(register int j=last[i];j;j=ed[j].prev)
		{
			mp[ed[j].to][dist[i]]++;
		}
	}
	for(register int i=2;i<=cnt;i++)
	{
		if(dist[x[i-1]]<=dist[x[i]])
		{
			mi++,ma++;
		}
		else
		{
			if(mp[x[i-1]][dist[x[i]]]>1)
			{
				ma++;
			}
		}
	}
	write(mi),writeln(ma);
}