// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
// }}}
// #defines {{{
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x);
#define PR printf
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
typedef pair<int,int> pii;
// }}}
// #functions {{{
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
template <class T>
T gcd(T a,T b) { a=abs(a); b=abs(b); while(b) { T t=b; b=a%b; a=t; } return a; }
template <class T>
pair<T,T> ext_gcd(T a,T b) {
   T a0=1,a1=0,b0=0,b1=1;
   if(a<0) { a=-a; a0=-1; }
   if(b<0) { b=-b; b1=-1; }
   while(b) {
      T t,q=a/b;
      t=b; b=a-b*q; a=t;
      t=b0; b0=a0-b0*q; a0=t;
      t=b1; b1=a1-b1*q; a1=t;
   }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define MAXK 10

const int mod = 1000000007;

int n,k,cnt;
int to[MAXK];
int vis[MAXK],ok[MAXK],visid=0;

inline int power(int x,int p) {
   int m=x%mod,r=1;
   while(p) {
      if(p&1) r=(long long)r*m%mod;
      p>>=1;
      m=(long long)m*m%mod;
   }
   return r;
}

bool valid() {
   ++visid;
   for(int v=1;v<=k;v++)
      ok[v]=0;
   vis[1]=visid;
   ok[1]=1;
   for(int v=2;v<=k;v++) {
      if(vis[v]==visid) continue;
      int u;
      for(u=v;vis[u]<visid;u=to[u])
         vis[u]=visid;
      if(!ok[u]) return 0;
      for(u=v;!ok[u];u=to[u])
         ok[u]=1;
   }
   return 1;
}

void dfs(int v) {
   if(v>k) {
      if(valid()) cnt++;
      return;
   }
   for(int i=1;i<=k;i++) {
      to[v]=i;
      dfs(v+1);
   }
}

int solve() {
   cnt=0;
   dfs(2);
   return (long long)cnt*k%mod*power(n-k,n-k)%mod;
}

int main(void) {
   RII(n,k);
   printf("%d\n",solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread