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
#define MAXV 300500

int rn,cn,vn;
vector<int> cols[MAXN];
int carr[MAXN];
//int eq[MAXN];

vector<int> adj[MAXV];
bool vis[MAXV],instk[MAXV];
int ts[MAXV],tid=0;
vector<int> topo;

//int acc;
//bool cmp() {
//}

/*bool cmpnil(int ca,int cb) {
   for(int i=0;i<rn;i++)
      if((cols[ca][i]<0)^(cols[cb][i]<0)) return cols[ca][i]<0;
   return 0;
}*/

bool dfs(int v) {
   ts[v]=tid++;
   vis[v]=1;
   instk[v]=1;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      //printf("%d -> %d\n",v,u);
      if(vis[u]) {
         if(instk[u]) return 1;
         continue;
      }
      if(dfs(u)) return 1;
   }
   topo.PB(v);
   instk[v]=0;
   return 0;
}

bool solve() {
  /* for(int i=0;i<cn;i++)
      carr[i]=i;
   sort(carr,carr+cn,cmpnil);
   memset(eq,-1,sizeof(eq));
   for(int i=0;i<cn;i++) {
      
   }
   for(int r=0;r<rn;r++) {
   }*/
   vn=cn;
   for(int r=0;r<rn;r++) {
      vector<pii> arr;
      for(int c=0;c<cn;c++) {
         if(cols[c][r]<0) continue;
         arr.PB(MP(cols[c][r],c));
      }
      sort(arr.begin(),arr.end());
      for(int i=0,j=0,pv=-1;i<arr.size();i=j) {
         for(j=i;j<arr.size()&&arr[i].F==arr[j].F;j++) {
            int cj=arr[j].S;
            if(pv>=0) adj[pv].PB(cj);
            adj[cj].PB(vn);
         }
         pv=vn++;
      }
   }
   for(int i=0;i<vn;i++) {
      if(vis[i]) continue;
      //ttt=tid;
      if(dfs(i)) return 0;
      //dfs(i);
   }
   for(int i=topo.size()-1;i>=0;i--) {
      int v=topo[i];
      if(v<cn) printf("%d ",v+1);
   }
   puts("");
   return 1;
}

int main(void) {
   RII(rn,cn);
   for(int i=0;i<cn;i++)
      cols[i].resize(rn);
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         RI(cols[j][i]);
   if(!solve()) puts("-1");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread