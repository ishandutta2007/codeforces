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

#define MAXN 15000
#define MAXVN MAXN // define as needed: # of nodes in graph
// inf has to be appropriately initialized: at least MAXVN for example

const int inf=1000000010;

class Arc {
   public:
      int to,revind;
      int flow,cap;
      Arc(int _to,int _revind,int _cap):to(_to),revind(_revind),cap(_cap),flow(0) {}
};

class DinicFlow {
   public:
      /* initialize the following using constructor and append */
      int vn,src,sink;
      vector<Arc> adj[MAXVN];
      /* helper variables */
      int dist[MAXVN];
      int ql,qr,que[MAXVN];
      int iter[MAXVN];
      /* primary functions */
      DinicFlow(int _vn,int _src,int _sink):vn(_vn),src(_src),sink(_sink) {}
      void append(int v,int u,int c) {
         int vid=adj[v].size(),uid=adj[u].size();
         adj[v].push_back(Arc(u,uid,c));
         adj[u].push_back(Arc(v,vid,0));
      }
      void bfs_layer() {
         ql=qr=0;
         for(int i=0;i<vn;i++)
            dist[i]=inf;
         que[qr++]=src;
         dist[src]=0;
         while(ql<qr) {
            int v=que[ql++];
            for(int i=0;i<adj[v].size();i++) {
               int u=adj[v][i].to;
               int res=adj[v][i].cap-adj[v][i].flow;
               if(dist[u]<inf) continue;
               if(!res) continue;
               que[qr++]=u;
               dist[u]=dist[v]+1;
            }
         }
      }
      int dfs_push(int v,int a) {
         if(v==sink) return a;
         int pushed=0;
         for(int &i=iter[v];i<adj[v].size();i++) {
            int u=adj[v][i].to;
            int res=adj[v][i].cap-adj[v][i].flow;
            if(dist[u]!=dist[v]+1) continue;
            if(!res) continue;
            int ri=adj[v][i].revind;
            int pf=dfs_push(u,min(a-pushed,res));
            adj[v][i].flow+=pf;
            adj[u][ri].flow-=pf;
            pushed+=pf;
            if(pushed==a) break;
         }
         return pushed;
      }
      int push_flow() {
         bfs_layer();
         for(int i=0;i<vn;i++)
            iter[i]=0;
         return dfs_push(src,inf);
      }
      int maxflow() {
         // O(mn^2) in general graph
         // good complexity in bipartite / unit-capcity graph
         int f=0;
         while(1) {
            int pf=push_flow();
            if(!pf) break;
            f+=pf;
         }
         return f;
      }
      /* selective functions */
      vector<pii> mincut() {
         // must run maxflow() first
         // will return the mincut "closest" to src
         bfs_layer();
         vector<pii> cut;
         for(int v=0;v<vn;v++) {
            for(int i=0;i<adj[v].size();i++) {
               int u=adj[v][i].to;
               if(dist[v]<inf&&dist[u]==inf) cut.push_back(make_pair(v,u));
            }
         }
         return cut;
      }
      vector<int> srccut() {
         bfs_layer();
         vector<int> vs;
         for(int v=0;v<vn;v++)
            if(dist[v]<inf) vs.push_back(v);
         return vs;
      }
      vector<int> sinkcut() {
         bfs_layer();
         vector<int> vs;
         for(int v=0;v<vn;v++)
            if(dist[v]==inf) vs.push_back(v);
         return vs;
      }
      bool mincut_is_isolated_sink() {
         // return whether cut is {sink} -- {V\sink}
         // useful for handling binary search problems where you don't
         // want the sink to be the only node at one side of the cut
         return sinkcut().size()==1;
      }
};


int nsub,nplan,pen;
int osex[MAXN],tran[MAXN];
int base;

inline int vsub(int x) { return x+1; }
inline int vplan(int x) { return nsub+x+1; }

int main(void) {
   RIII(nsub,nplan,pen);
   int vn=nsub+nplan+2;
   int src=0;
   int sink=vn-1;
   base=0;
   DinicFlow df(vn,src,sink);
   for(int i=0;i<nsub;i++)
      RI(osex[i]);
   for(int i=0;i<nsub;i++) {
      RI(tran[i]);
      if(osex[i]) df.append(vsub(i),sink,tran[i]);
      else df.append(src,vsub(i),tran[i]);
   }
   for(int i=0;i<nplan;i++) {
      //DPRI(i);
      int goal,reward,num,isfriend;
      RIII(goal,reward,num);
      for(int t=0;t<num;t++) {
         int u;
         RI(u); u--;
         if(goal) df.append(vsub(u),vplan(i),inf);
         else df.append(vplan(i),vsub(u),inf);
      }
      RI(isfriend);
      int rc=reward+(isfriend?pen:0);
      base+=reward;
      if(goal) df.append(vplan(i),sink,rc);
      else df.append(src,vplan(i),rc);
   }
   int mincost=df.maxflow();
   int sol=base-mincost;
   //DPRIII(base,mincost,sol);
   PRI(sol);
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread