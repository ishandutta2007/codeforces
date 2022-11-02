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
#define RIII(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x)
#define PRII(x,y) printf("%d %d\n",x,y)
#define PRIII(x,y,z) printf("%d %d %d\n",x,y,z);
#define DPRI(x) fprintf(stderr,"<"#x"=%d>\n",x)
#define DPRII(x,y) fprintf(stderr,"<"#x"=%d, "#y"=%d>\n",x,y)
#define DPRIII(x,y,z) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d>\n",x,y,z)
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
   T a0=1,a1=0,b0=0,b1=1; if(a<0) { a=-a; a0=-1; } if(b<0) { b=-b; b1=-1; }
   while(b) { T t,q=a/b; t=b; b=a-b*q; a=t; t=b0; b0=a0-b0*q; a0=t; t=b1; b1=a1-b1*q; a1=t; }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

// DisjointSet {{{
class DisjointSet {
   public:
      int n;
      int *rep,*rank;
      DisjointSet(int _n):n(_n) {
         rep=new int[n];
         rank=new int[n];
         for(int i=0;i<n;i++)
            rep[i]=i;
      }
      ~DisjointSet() {
         delete [] rep;
         delete [] rank;
      }
      int getrep(int v) {
         if(rep[v]!=v) rep[v]=getrep(rep[v]);
         return rep[v];
      }
      bool merge(int v,int u) {
         v=getrep(v);
         u=getrep(u);
         if(v==u) return 0;
         if(rank[v]<rank[u]) {
            rep[v]=u;
         } else {
            rep[u]=v;
            if(rank[v]==rank[u]) rank[v]++;
         }
         return 1;
      }
};
// }}}

#define MAXN 330

int n,cap,ne;
int cur[MAXN],goal[MAXN];
vector<int> adj[MAXN];

vector<int> order;
vector<pair<pii,int> > seq;
bool vis[MAXN],inactive[MAXN];

void dfs(int v) {
   vis[v]=1;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(vis[u]) continue;
      dfs(u);
   }
   order.PB(v);
}

int suck(int v,int req,int p,bool fixed) {
   //DPRIII(v,req,p);
   vis[v]=1;
   int ret=0;
   if(!fixed) {
      int a=min(cur[v],req);
      ret+=a;
      cur[v]-=a;
      req-=a;
   }
   for(int i=0;req&&i<adj[v].size();i++) {
      int u=adj[v][i];
      if(vis[u]) continue;
      if(inactive[u]) continue;
      int uret=suck(u,req,v,0);
      ret+=uret;
      req-=uret;
   }
   if(!fixed) seq.PB(MP(MP(v,p),ret));
   return ret;
}

int push(int v,int req,int p,bool fixed) {
   vis[v]=1;
   int ret=0;
   if(!fixed) {
      int a=min(cap-cur[v],req);
      ret+=a;
      cur[v]+=a;
      req-=a;
   }
   for(int i=0;req&&i<adj[v].size();i++) {
      int u=adj[v][i];
      if(vis[u]) continue;
      if(inactive[u]) continue;
      int uret=push(u,req,v,0);
      ret+=uret;
      req-=uret;
      seq.PB(MP(MP(v,u),uret));
   }
   return ret;
}

bool solve() {
   for(int v=1;v<=n;v++)
      if(!vis[v]) dfs(v);
   for(int o=0;o<n;o++) {
      int v=order[o];
      memset(vis,0,sizeof(vis));
      if(cur[v]>goal[v]) {
         int amt=cur[v]-goal[v];
         int ret=push(v,amt,-1,1);
         //fprintf(stderr,"push %d\n",v);
         //DPRII(amt,ret);
         if(ret!=amt) return 0;
      } else if(cur[v]<goal[v]) {
         int amt=goal[v]-cur[v];
         int ret=suck(v,amt,-1,1);
         //fprintf(stderr,"suck %d\n",v);
         //DPRII(amt,ret);
         if(ret!=amt) return 0;
      }
      inactive[v]=1;
   }
   PRI((int)seq.size());
   for(int i=0;i<seq.size();i++)
      PRIII(seq[i].F.F,seq[i].F.S,seq[i].S);
   return 1;
}

int main(void) {
   RIII(n,cap,ne);
   DisjointSet djs(n+1);
   for(int i=1;i<=n;i++)
      RI(cur[i]);
   for(int i=1;i<=n;i++)
      RI(goal[i]);
   for(int i=0;i<ne;i++) {
      int v,u;
      RII(v,u);
      if(djs.getrep(v)==djs.getrep(u)) continue;
      //DPRII(v,u);
      djs.merge(v,u);
      adj[v].PB(u);
      adj[u].PB(v);
   }
   if(!solve()) puts("NO");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread