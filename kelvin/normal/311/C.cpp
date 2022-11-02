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

#define MAXT 100050
#define MAXQ 100050
#define MAXM 10050

typedef pair<long long,int> pli;
const long long infll=1000000000000000010LL;

int tn,qn,mod;
long long maxl;
int tval[MAXT];
vector<pli> ge[MAXM];
long long dp[MAXM];
priority_queue<pii> tque;
vector<long long> moves;
bool released[MAXT];

void newmove(long long dx=0) {
   if(dx) moves.PB(dx);
   priority_queue<pli,vector<pli>,greater<pli> > pq;
   for(int v=0;v<mod;v++)
      pq.push(MP(dp[v],v));
   while(pq.size()) {
      int v=pq.top().S;
      long long dpv=pq.top().F;
      pq.pop();
      if(dpv!=dp[v]) continue;
      if(dpv>=infll) break;
      for(int i=0;i<moves.size();i++) {
         long long u=(v+moves[i])%mod;
         long long dpu=dpv+(v+moves[i])/mod;
         if(dpu<dp[u]) {
            dp[u]=dpu;
            pq.push(MP(dp[u],u));
         }
      }
   }
   for(int v=0;v<mod;v++) {
      while(ge[v].size()&&ge[v].back().F>=dp[v]) {
         int i=ge[v].back().S;
         ge[v].POP();
         tque.push(MP(tval[i],-i));
         released[i]=1;
      }
   }
}

void reduce(int ti,long long val) {
   tval[ti]-=val;
   if(released[ti]) tque.push(MP(tval[ti],-ti));
}

long long query() {
   int ti=-1;
   long long val;
   while(tque.size()) {
      ti=-tque.top().S;
      val=tque.top().F;
      tque.pop();
      if(tval[ti]==val) break;
   }
   if(ti<0||tval[ti]!=val) return 0;
   tval[ti]=-1;
   return val;
}

int main(void) {
#ifdef ONLINE_JUDGE
   scanf("%I64d %d %d %d",&maxl,&tn,&qn,&mod);
#else
   scanf("%lld %d %d %d",&maxl,&tn,&qn,&mod);
#endif
   for(int i=0;i<tn;i++) {
      int c;
      long long x;
#ifdef ONLINE_JUDGE
      scanf("%I64d %d",&x,&c);
#else
      scanf("%lld %d",&x,&c);
#endif
      x--;
      tval[i]=c;
      ge[x%mod].PB(MP(x/mod,i));
   }
   for(int i=0;i<mod;i++) {
      dp[i]=infll;
      sort(ge[i].begin(),ge[i].end());
   }
   dp[0]=0;
   newmove();
   for(int qi=0;qi<qn;qi++) {
      int cmd;
      scanf("%d",&cmd);
      if(cmd==1) { // new move
         long long dx;
#ifdef ONLINE_JUDGE
         scanf("%I64d",&dx);
#else
         scanf("%lld",&dx);
#endif
         newmove(dx);
      } else if(cmd==2) { // reduce treasure value
         int ti,dec;
         scanf("%d %d",&ti,&dec);
         ti--;
         reduce(ti,dec);
      } else { // query and take treasure
         long long res=query();
#ifdef ONLINE_JUDGE
         printf("%I64d\n",res);
#else
         printf("%lld\n",res);
#endif
      }
   }
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread