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
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define MAXN 320
#define MAXVAL 200500

const int mod=1000000007;

int n,m,tot;
int vv[MAXN];
int out[MAXN],in[MAXN];

int init;
vector<int> cset;
int dep[MAXN];
int dp[MAXVAL];
bool vis[MAXN];

void dfs(int v,int s) {
   vis[v]=1;
   dep[v]=0;
   int u=out[v];
   s+=vv[v];
   if(u) {
      dfs(u,s);
      dep[v]=dep[u]+1;
   } else dep[u]=0;
   init+=vv[v]*dep[v];
   if(init>tot) init=tot+1;
   cset.PB(s);
}

inline int modit(int x) {
   if(x<0) x+=mod;
   if(x>=mod) x-=mod;
   return x;
}

int solve() {
   init=0;
   for(int i=1;i<=n;i++)
      if(in[i]==0) dfs(i,0);
   for(int i=1;i<=n;i++)
      if(!vis[i]) return 0;
   if(init>tot) return 0;
   tot-=init;
   dp[0]=1;
   /*printf("<%d>\n",tot);
   for(int i=0;i<cset.size();i++)
      printf(" %d",cset[i]); puts("");*/
   for(int i=0;i<cset.size();i++) {
      int x=cset[i];
      for(int j=0;j+x<=tot;j++)
         dp[j+x]=modit(dp[j+x]+dp[j]);
   }
   return dp[tot];
}

int main(void) {
   RI(n);
   RI(m);
   RI(tot);
   for(int i=1;i<=n;i++)
      RI(vv[i]);
   for(int i=0;i<m;i++) {
      int v,u;
      RII(v,u);
      out[v]=u;
      in[u]=v;
   }
   printf("%d\n",solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread