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
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define MAXN 200500

int n,stk[MAXN];
long long sum;
priority_queue<pii> pq;

int main(void) {
   int qn;
   RI(qn);
   n=1;
   stk[0]=0;
   sum=0;
   for(int qi=0;qi<qn;qi++) {
      int cmd;
      RI(cmd);
      if(cmd==1) {
         int x,a;
         RII(a,x);
         pq.push(MP(a,x));
         sum+=a*x;
      } else if(cmd==2) {
         int x;
         RI(x);
         stk[n++]=x;
         sum+=x;
      } else {
         long long d=0;
         while(pq.size()&&pq.top().F>=n) {
            d+=pq.top().S;
            pq.pop();
         }
         sum-=stk[--n];
         sum-=d;
         pq.push(MP(n,d));
      }
      double avg=(long double)sum/n;
      printf("%.12lf\n",avg);
   }
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread