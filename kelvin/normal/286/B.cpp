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

#define MAXN 1500600

int n;
int s[MAXN*2];

void solve() {
   int lb=0;
   for(int i=0;i<n;i++)
      s[i]=i;
   for(int t=2;t<=n;t++) {
      int i=0;
      while(i<n) i+=t;
      for(;i>=t;i-=t) {
         if(i>=n) s[lb+n]=s[lb+i-t];
         else s[lb+i]=s[lb+i-t];
      }
      lb++;
   }
   for(int i=0;i<n;i++)
      printf("%d ",s[lb+i]+1); puts("");
}

int main(void) {
   RI(n);
   solve();
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread