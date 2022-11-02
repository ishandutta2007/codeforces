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
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
#define PR printf
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RIII(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x)
#define PRII(x,y) printf("%d %d\n",x,y)
#define DPRI(x) fprintf(stderr,"<"#x"=%d>\n",x)
#define DPRII(x,y) fprintf(stderr,"<"#x"=%d, "#y"=%d>\n",x,y)
#define DPRIII(x,y,z) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d>\n",x,y,z)
#define DPRS(x) fprintf(stderr,"<"#x"=%s>\n",x)
#define DPRMSG(x) fprintf(stderr,#x"\n")
#define DPRPII(x) fprintf(stderr,"<"#x"=(%d,%d)>\n",x.F,x.S)
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
   T a0=1,a1=0,b0=0,b1=1; if(a<0) { a=-a; a0=-1; } if(b<0) { b=-b; b1=-1; }
   while(b) { T t,q=a/b; t=b; b=a-b*q; a=t; t=b0; b0=a0-b0*q; a0=t; t=b1; b1=a1-b1*q; a1=t; }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define MAXN 100500

const int maxval=(1<<26)-1;

int n;
vector<int> adj[MAXN];
bool vis[MAXN];
int sol[MAXN];
int cnt[30];

bool dfs(int v) {
   vis[v]=1;
   int z=0;
   //int a=~0;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(vis[u]) continue;
      if(!dfs(u)) return 0;
   }
   memset(cnt,0,sizeof(cnt));
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      //if(vis[u]) continue;
      z|=sol[u];
      //a&=sol[u];
      //cc++;
      for(int t=0;t<26;t++)
         if(sol[u]&(1<<t)) cnt[t]++;
   }
   //DPRI(z);
   for(int t=26;t>=0;t--) {
      if(cnt[t]>1) {
         z|=(1<<t+1)-1;
         break;
      }
   }
   //DPRI(z);
   sol[v]=z+1;
   //DPRI(sol[v]);
   if(sol[v]>maxval) return 0;
   return 1;
}

inline char tran(int z) {
   for(int t=0;t<26;t++)
      if(z&(1<<t)) return 'Z'-t;
}

bool solve() {
   if(!dfs(1)) return 0;
   for(int i=1;i<=n;i++)
      printf("%c%c",tran(sol[i]),i<n?' ':'\n');
   return 1;
}

int main(void) {
   RI(n);
   for(int i=0;i<n-1;i++) {
      int v,u;
      RII(v,u);
      adj[v].PB(u);
      adj[u].PB(v);
   }
   if(!solve()) puts("Impossible!");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread