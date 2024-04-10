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

#define MAXN 100500

int n;
int s[MAXN];

bool solve() {
   if((n&3)==2||(n&3)==3) return 0;
   if((n&3)==1) s[n>>1]=n>>1;
   int cc=n>>2;
   for(int i=0;i<cc;i++) {
      int b=i<<1;
      s[b]=n-b-2;
      s[n-b-2]=n-b-1;
      s[n-b-1]=b+1;
      s[b+1]=b;
   }
   for(int i=0;i<n;i++)
      printf("%d ",s[i]+1); puts("");
   return 1;
}

int main(void) {
   RI(n);
   if(!solve()) puts("-1");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread