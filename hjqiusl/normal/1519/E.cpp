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
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,x,y,a,vis[N],Us[N],Mth[N],ed,b,id,Now[N],sig;
struct node
{
	int u,v,id;
};
vector<node>G[N];
vector<pa>ans;
map<pa,int>M;
void ad(int x,int y,int z)
{
	G[y].push_back({x,z,++ed});
	G[x].push_back({y,z,ed});
}
void dfs(int k)
{
	vis[k]=1;
	for (auto u:G[k])
	{
		if (Us[u.id]) continue;
		Us[u.id]=1;
		if (!vis[u.u]) dfs(u.u);
		if (Mth[u.u]) ans.push_back({u.v,Mth[u.u]}),Mth[u.u]=0;
		else if (Mth[k]) ans.push_back({u.v,Mth[k]}),Mth[k]=0;
		else Mth[k]=u.id;
	}
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		x=read(),y=read(),a=read(),b=read();
		int u=__gcd((x+y)*b,y*a);
		if (!(M[{(x+y)*b/u,y*a/u}])) M[{(x+y)*b/u,y*a/u}]=++id;
		u=__gcd((x)*b,y*(a+b));
		if (!M[{(x)*b/u,y*(a+b)/u}]) M[{(x)*b/u,y*(a+b)/u}]=++id;
		ad(M[{(x+y)*b/__gcd((x+y)*b,y*a),y*a/__gcd((x+y)*b,y*a)}],M[{(x)*b/u,y*(a+b)/u}],i);
	}
	for (int i=1;i<=id;i++)
		if (!vis[i])
		{
			dfs(i);
		}
	writeln(ans.size());
	for (auto u:ans)
	{
		writesp(u.fi),writeln(u.se);
	}
		
	
}
/*

*/