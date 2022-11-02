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

#define MAXN 100500

class Ret {
   public:
      long long mi,ma;
      Ret(int _mi,int _ma):mi(_mi),ma(_ma) {}
};

int n;
vector<int> adj[MAXN];
int val[MAXN];

Ret dfs(int v,int p) {
   Ret rv(0,0);
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u==p) continue;
      Ret ru=dfs(u,v);
      //rv.d+=ru.d;
      rv.ma=max(rv.ma,ru.ma);
      rv.mi=max(rv.mi,ru.mi);
   }
   if(val[v]>rv.ma-rv.mi) rv.ma+=val[v]-(rv.ma-rv.mi);
   else rv.mi+=(rv.ma-rv.mi)-val[v];
   //int ch=val[v]-rv.d;
   //rv.d+=ch;
   //if(ch>=0) rv.ma+=ch;
   //else rv.mi+=-ch;
   return rv;
}

long long solve() {
   Ret ret=dfs(1,1);
   long long sol=abs(ret.mi)+abs(ret.ma);
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
   for(int i=1;i<=n;i++)
      RI(val[i]);
   //printf("%d\n",solve());
   cout << solve() << endl;
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread