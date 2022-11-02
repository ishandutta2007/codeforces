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

int n,m;

bool solve() {
   if(n==3) {
      if(m!=3) return 0;
      printf("0 0\n");
      printf("0 1\n");
      printf("1 0\n");
      return 1;
   }
   if(n==4) {
      if(m!=3&&m!=4) return 0;
      if(m==3) {
         printf("0 1\n");
         printf("1 0\n");
         printf("1 1\n");
         printf("2 2\n");
      } else {
         printf("0 0\n");
         printf("0 1\n");
         printf("1 0\n");
         printf("1 1\n");
      }
      return 1;
   }
   if(n==5) {
      if(m!=4&&m!=5) return 0;
      if(m==4) {
         printf("0 0\n");
         printf("0 4\n");
         printf("4 0\n");
         printf("4 4\n");
         printf("1 2\n");
      } else {
         printf("0 0\n");
         printf("0 4\n");
         printf("4 0\n");
         printf("4 4\n");
         printf("1 5\n");
      }
      return 1;
   }
   if(n==6&&m==3) return 0;
   if(m*2<n) {
      return 0;
   }
   int h1=m,h2=n-m;
   vector<pii> pt;
   for(int i=0;i<h1;i++)
      printf("%d %d\n",i+1,(h1-i)*(h1-i));
   for(int i=0;i<h2;i++)
      printf("%d %d\n",-(i+1),-(h2-i)*(h2-i));
   return 1;
}

int main(void) {
   RII(n,m);
   if(!solve()) puts("-1");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread