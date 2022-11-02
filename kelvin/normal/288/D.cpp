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

#define MAXN 85000

int n;
vector<int> adj[MAXN];

long long up1[MAXN];
long long path1[MAXN];
long long path1up1[MAXN];
long long path2[MAXN];

void dfs(int v,int p) {
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u==p) {
         adj[v][i]=adj[v].back();
         adj[v].POP();
         i--;
         continue;
      }
      dfs(u,v);
   }
   // up1 = (v up) + sum(child's up1)
   up1[v]=1;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      up1[v]+=up1[u];
   }
   // path1 = sum(child's up1) + sum(child's path1) + sum(up1[a]*up1[b])
   path1[v]=0;
   long long ups=1;
   long long path1withv=0;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      path1[v]+=path1[u];
      path1[v]+=up1[u]*ups;
      path1withv+=up1[u]*ups;
      ups+=up1[u];
   }
   // path1up1 = sum(child's path1up1) + sum(path1[a] * (up1[v]-up1[a]))
   path1up1[v]=0;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      path1up1[v]+=path1up1[u];
      path1up1[v]+=path1[u]*(up1[v]-up1[u]);
   }
   // path2 = sum(child's path2)
   //         + sum(path1[a]*path1[b])
   //         + sum(path1[a]*(path1[v]-path1[a]-up1[a]*(ups-up1[a])))
   //         + sum(path1up1[a]*(ups-up1[a]))
   path2[v]=0;
   long long pas=0;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      path2[v]+=path2[u];
      path2[v]+=path1[u]*pas;
      path2[v]+=path1[u]*(path1withv-up1[u]*(ups-up1[u]));
      path2[v]+=path1up1[u]*(ups-up1[u]);
      pas+=path1[u];
   }
}

long long solve() {
   dfs(1,1);
   return path2[1]*2;
}

int main(void) {
   RI(n);
   for(int i=0;i<n-1;i++) {
      int v,u;
      RII(v,u);
      adj[v].PB(u);
      adj[u].PB(v);
   }
   cout << solve() << endl;
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread