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

#define MAXN 100050

const int maxp=30;
int tp[maxp+1];

int n,s[MAXN];

int sub() {
   vector<int> stk;
   int sol=0;
   for(int i=0;i<n;i++) {
      while(stk.size()&&stk.back()<s[i]) {
         sol=max(sol,stk.back()^s[i]);
         //printf("%d %d\n",stk.back(),s[i]);
         stk.POP();
      }
      stk.PB(s[i]);
   }
   return sol;
}

int solve() {
   int s1=sub();
   for(int i=0;i<n-i-1;i++)
      swap(s[i],s[n-i-1]);
   int s2=sub();
   return max(s1,s2);
}

int main(void) {
   for(int i=0;i<=maxp;i++)
      tp[i]=1<<i;
   RI(n);
   for(int i=0;i<n;i++)
      RI(s[i]);
   printf("%d\n",solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread