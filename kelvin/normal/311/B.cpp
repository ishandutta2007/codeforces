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

#define MAXN 100050
#define MAXF 105

typedef pair<long long,long long> pll;
const long long infll=100000000000000000ll;

int npos,ncat,nfeed;
int x[MAXN];
vector<int> ts;
long long sum[MAXN];
long long dp[MAXN];

int ql,qr;
pll que[MAXN];

inline long long getsum(int l,int r) {
   return sum[r+1]-sum[l];
}

inline void relax(long long &x,long long val) {
   x=min(x,val);
}

inline long long cross(pll a,pll b) {
   return a.F*b.S-a.S*b.F;
}
inline long long cross(pll o,pll a,pll b) {
   return cross(MP(a.F-o.F,a.S-o.S),MP(b.F-o.F,b.S-o.S));
}

inline void insert(pll p) {
   while(ql+1<qr&&cross(que[qr-2],que[qr-1],p)<=0) --qr;
   que[qr++]=p;
}

long long solve() {
   sort(ts.begin(),ts.end());
   int perseg=ncat/nfeed;
   int addone=ncat%nfeed;
   sum[0]=0;
   for(int i=0;i<ncat;i++)
      sum[i+1]=sum[i]+ts[i];
   for(int i=0;i<=ncat;i++)
      dp[i]=infll;
   dp[0]=0;
   for(int ttt=0;ttt<nfeed;ttt++) {
      ql=qr=0;
      //que[qr++]=MP(0ll,dp[0]-sum[0]);
      insert(MP(0ll,dp[0]-sum[0]));
      //long long curmin=dp[0]-0*t;
      int j=0;
      for(int i=1;i<=ncat;i++) {
         long long t=ts[i-1];
         if(dp[i]<infll) {
            insert(MP((long long)i,dp[i]+sum[i]));
         }
         j=min(j,qr-1);
         long long z=t*i-sum[i];
         while(j+1<qr&&que[j].S-t*que[j].F>=que[j+1].S-t*que[j+1].F)
            ++j;
         relax(dp[i],z+que[j].S-t*que[j].F);
         //relax(dp[ni][j+1],dp[i][j]+(long long)t*cc-getsum(i,ni-1));
      }
   }
   /*long long sol=infll;
   for(int j=0;j<=nfeed;j++)
      relax(sol,dp[ncat][j]);*/
   return dp[ncat];
}

int main(void) {
   RI(npos);
   RI(ncat);
   RI(nfeed);
   x[0]=0;
   for(int i=1;i<npos;i++) {
      int d;
      RI(d);
      x[i]=x[i-1]+d;
   }
   ts.reserve(ncat);
   for(int i=0;i<ncat;i++) {
      int h,t;
      RII(h,t); h--;
      ts.PB(t-x[h]);
   }
   cout << solve() << endl;
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread