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

#define MAXN 105

const int inf=400000000;

int n,coef;
int add[MAXN];
pii pt[MAXN];
int dp[MAXN];
int dis[MAXN][MAXN];

bool valid(int init) {
   for(int i=0;i<n;i++)
      dp[i]=-inf;
   dp[0]=init;
   bool upd;
   do {
      upd=0;
      for(int i=0;i<n;i++) {
         if(dp[i]<0) continue;
         for(int j=0;j<n;j++) {
            if(i==j) continue;
            if(dp[i]<dis[i][j]) continue;
            if(dp[i]-dis[i][j]+add[j]>dp[j]) {
               dp[j]=dp[i]-dis[i][j]+add[j];
               upd=1;
            }
         }
      }
   } while(upd);
   return dp[n-1]>=0;
}

int solve() {
   for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         dis[i][j]=(abs(pt[i].F-pt[j].F)+abs(pt[i].S-pt[j].S))*coef;
   int l=-1,r=inf;
   while(l<r-1) {
      int m=(l+r)>>1;
      if(valid(m)) r=m;
      else l=m;
   }
   return r;
}

int main(void) {
   RII(n,coef);
   add[0]=add[n-1]=0;
   for(int i=1;i<n-1;i++)
      RI(add[i]);
   for(int i=0;i<n;i++)
      RII(pt[i].F,pt[i].S);
   printf("%d\n",solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread