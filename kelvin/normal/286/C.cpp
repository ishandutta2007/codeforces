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

#define MAXN 1000500

typedef map<int,int> mii;

int len,neg;
int a[MAXN],npos[MAXN];
int s[MAXN];

int sz;
pii stk[MAXN];

bool collapse() {
   //printf("(%d %d)\n",stk[sz-1].F,stk[sz-1].S);
   s[stk[sz-1].S]=-abs(s[stk[sz-1].S]);
   int x=stk[--sz].F;
   while(sz&&stk[sz-1].F!=x) {
      if(!collapse()) return 0;
   }
   if(sz==0) return 0;
   --sz;
   return 1;
}

bool solve() {
   for(int i=0;i<len;i++)
      s[i]=a[i];
   for(int i=0;i<neg;i++) {
      int p=npos[i];
      s[p]=-s[p];
   }
   sz=0;
   for(int i=0;i<len;i++) {
      int x=abs(s[i]);
      stk[sz++]=MP(x,i);
      if(s[i]<0) {
         if(!collapse()) return 0;
      }
   }
   while(sz) {
      if(!collapse()) return 0;
   }
   puts("YES");
   for(int i=0;i<len;i++)
      printf("%d ",s[i]); puts("");
   return 1;
}

int main(void) {
   RI(len);
   for(int i=0;i<len;i++)
      RI(a[i]);
   RI(neg);
   for(int i=0;i<neg;i++) {
      RI(npos[i]);
      npos[i]--;
   }
   if(!solve()) puts("NO");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread