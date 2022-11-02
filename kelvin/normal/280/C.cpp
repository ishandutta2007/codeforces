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

#define MAXN 100050

int n;
vector<int> adj[MAXN];
int pred[MAXN];
//inr sub[MAXN];

void dfs(int v,int p) {
   //sub[v]=0;
   pred[v]=pred[p]+1;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u==p) continue;
      dfs(u,v);
      //sub[v]+=1+sub[u];
   }
}

double solve() {
   pred[0]=-1;
   dfs(1,0);
   double sol=.0;
   for(int v=1;v<=n;v++)
      sol+=1.0/(pred[v]+1);
   return sol;
}

int main(void) {
   RI(n);
   for(int i=0;i<n-1;i++) {
      int v,u;
      RII(v,u);
      adj[v].PB(u);
      adj[u].PB(v);
   }
   printf("%.12lf\n",solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread