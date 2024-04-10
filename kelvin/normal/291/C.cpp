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
#include <bitset>
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

#define MAXN 100500

const unsigned maxuint=0xFFFFFFFFu;

int n,k;
unsigned ip[MAXN];

bool valid(unsigned mask) {
   set<unsigned> bset;
   for(int i=0;i<n;i++)
      bset.insert(ip[i]&mask);
   return bset.size()==k;
}

bool solve() {
   for(unsigned b=0x80000000;b<maxuint;b|=(b&-b)>>1) {
      if(valid(b)) {
         printf("%u.%u.%u.%u\n",(b>>24),(b>>16)&255,(b>>8)&255,(b)&255);
         return 1;
      }
   }
   return 0;
}

int main(void) {
   RII(n,k);
   for(int i=0;i<n;i++) {
      unsigned a,b,c,d;
      scanf("%u.%u.%u.%u",&a,&b,&c,&d);
      ip[i]=(a<<24)|(b<<16)|(c<<8)|(d);
   }
   if(!solve()) puts("-1");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread