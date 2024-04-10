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

#define MAXN 305

int n,m,vn;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int v) {
   vis[v]=1;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(vis[u]) continue;
      dfs(u);
   }
}

int solve() {
   bool allzero=1;
   for(int i=0;i<n;i++)
      if(adj[i].size()) allzero=0;
   if(allzero) return n;
   int c=0;
   for(int i=0;i<n;i++) {
      if(!vis[i]) {
         dfs(i);
         c++;
      }
   }
   return c-1;
}

int main(void) {
   RII(n,m);
   vn=n+m;
   for(int i=0;i<n;i++) {
      int j,k;
      RI(k);
      while(k--) {
         RI(j);
         adj[i].PB(n+j-1);
         adj[n+j-1].PB(i);
      }
   }
   printf("%d\n",solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread