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

#define MAXN 505
#define MAXVN (MAXN*2+2)

const double eps=1e-8;
const double inf=1e9;
const int maxrun=5000000;
inline double sqr(double x) { return x*x; }

int n;
pii pt[MAXN];

int vn,src,sink;
vector<int> adj[MAXVN];
int res[MAXVN][MAXVN];
double cost[MAXVN][MAXVN];

int pred[MAXVN];
double dist[MAXVN];
int ql,qr,que[MAXVN*MAXVN];
bool instk[MAXVN];

inline int in(int v) { return v+1; }
inline int out(int v) { return v+n+1; }

inline void append(int v,int u,int r,double c) {
   adj[v].PB(u);
   if(v!=src&&u!=sink) adj[u].PB(v);
   res[v][u]=r;
   res[u][v]=0;
   cost[v][u]=c;
   cost[u][v]=-c;
}

bool bfs() {
   ql=qr=0;
   que[qr++]=src;
   for(int i=0;i<vn;i++)
      dist[i]=inf;
   dist[src]=.0;
   instk[src]=1;
   while(ql<qr) {
      int v=que[ql++];
      //printf("<%d>\n",v);
      instk[v]=0;
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i];
         if(!res[v][u]) continue;
         //printf("<%d %d>\n",v,u);
         double d=dist[v]+cost[v][u];
         if(d>=dist[u]-eps) continue;
         dist[u]=d;
         if(!instk[u]) {
            que[qr++]=u;
            instk[u]=1;
         }
         pred[u]=v;
      }
   }
   return dist[sink]<inf-eps;
}

inline void augment() {
   int v=sink;
   while(v!=src) {
      //printf("%d->%d, ",v,pred[v]);
      res[v][pred[v]]++;
      res[pred[v]][v]--;
      v=pred[v];
   }//puts("");
}

bool solve() {
   src=0;
   sink=n*2+1;
   vn=sink+1;
   for(int i=0;i<n;i++) {
      append(src,in(i),2,0.0);
      append(out(i),sink,1,0.0);
   }
   for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
         // i->j
         if(pt[i].S<=pt[j].S) continue;
         double c=sqrt(sqr(pt[i].F-pt[j].F)+sqr(pt[i].S-pt[j].S));
         append(in(i),out(j),1,c);
      }
   }
   int f=0;
   double c=.0;
   while(bfs()) {
      augment();
      f++;
      c+=dist[sink];
   }
   //printf("<%d %.4lf>\n",f,c);
   if(f<n-1) return 0;
   printf("%.12lf\n",c);
   return 1;
}

int main(void) {
   RI(n);
   for(int i=0;i<n;i++)
      RII(pt[i].F,pt[i].S);
   if(!solve()) puts("-1");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread