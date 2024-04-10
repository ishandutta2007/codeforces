//QwQcOrZ yyds!!!
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
//#define int ll
#define N 400005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,zihuan[N],bel[N],ru[N],Inf[N],dis[N],cnt,sum[N],_,dfn[N],low[N],top,sta[N],vis[N];
vector<int>G[N],E[N],g;
queue<int>q;
void ad(int x,int y)
{
	G[x].push_back(y);
}
void ad1(int x,int y)
{
	E[x].push_back(y);ru[y]++;
}
void tarjan(int x)
{
	dfn[x]=++_;
	low[x]=dfn[x];
	sta[++top]=x;
	vis[x]=1;
	for (int v:G[x])
	{
		if (!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		} else
		if (vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if (dfn[x]==low[x])
	{
		++cnt;
		while (sta[top]!=x)
		{
			sum[cnt]++;
			bel[sta[top]]=cnt;
			vis[sta[top]]=0;
			top--;
		}
		sum[cnt]++;
		bel[sta[top]]=cnt;
		vis[sta[top]]=0;
		top--;
	}
}
signed main()
{
	T=read();int nmsl=0;
	while (T--)
	{
		n=read(),m=read();nmsl++;
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
//			if (nmsl<5) continue;
			if (u==v)
			{
				g.push_back(u);
			} else
			{
				ad(u,v);
			}
		}
//		if (nmsl<5) continue;
		cnt=0;_=0;top=0;
		for (int i=1;i<=n;i++)
			if (!bel[i]) tarjan(i);
		for (int i=1;i<=n;i++)
			for (auto u:G[i])
			{
				if (bel[i]!=bel[u])
				{
					ad1(bel[i],bel[u]);
				}
			}
		for (int u:g) zihuan[bel[u]]=1;
		for (int i=1;i<=cnt;i++) 
			if (!ru[i]) q.push(i),dis[i]=0;
		g.clear();
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			if (u==bel[1]) dis[u]=1;
			if (dis[u]!=0)
			{
				if (zihuan[u]||(sum[u]>1)) Inf[u]=1;
			}
			for (int v:E[u])
			{
				Inf[v]|=Inf[u];
				dis[v]=min(dis[v]+dis[u],2);
				ru[v]--;
				if (!ru[v]) q.push(v);
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (dis[bel[i]]==0) writesp(0);
			else
			if (Inf[bel[i]]) writesp(-1);
			else
			if (dis[bel[i]]==1) writesp(1);
			else
			if (dis[bel[i]]==2) writesp(2);
		}
		puts("");
		for (int i=1;i<=n;i++) G[i].clear(),E[i].clear();
		for (int i=1;i<=n;i++) dis[i]=0,Inf[i]=0,bel[i]=0,zihuan[i]=0,sum[i]=0,dfn[i]=0,low[i]=0,vis[i]=0,sta[i]=0;
	}
}