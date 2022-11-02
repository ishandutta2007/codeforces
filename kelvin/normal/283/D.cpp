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

#define MAXN 5050

int n;
long long s[MAXN];
int dp[MAXN];

inline void relax(int &x,int val) { if(val>x) x=val; }

pair<int,long long> analyze(long long x) {
   int c=0;
   while(!(x&1)) {
      x>>=1;
      c++;
   }
   return MP(c,x);
}

inline bool can(long long x,long long y,int d) {
   pair<int,long long> ax=analyze(x);
   pair<int,long long> ay=analyze(y);
   if(ax.S%ay.S) return 0;
   if(ay.F==ax.F+d) return 1;
   if(ay.F<=d-1) return 1;
   return 0;
}

int solve() {
   int opt=0;
   for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
         if(can(s[i],s[j],j-i)) relax(dp[j],dp[i]+1);
      }
      opt=max(opt,dp[i]+1);
   }
   return n-opt;
}

int main(void) {
   RI(n);
   for(int i=0;i<n;i++)
      cin >> s[i];
   printf("%d\n",solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread