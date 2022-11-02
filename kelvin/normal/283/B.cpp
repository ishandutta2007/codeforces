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

int n;
int s[MAXN];

long long sum[MAXN][2];
pii end[MAXN][2];
bool vis[MAXN][2];
bool instk[MAXN][2];

void dfs(int x,int b) {
   vis[x][b]=1;
   instk[x][b]=1;
   int a=(b&1)?-s[x]:s[x];
   int z=x+a;
   if(z<=1||z>n) {
      sum[x][b]=abs(a);
      end[x][b]=MP(z,!b);
   } else {
      if(instk[z][!b]) {
         sum[x][b]=-1;
         end[x][b]=MP(-1,-1);
      } else {
         if(!vis[z][!b]) dfs(z,!b);
         sum[x][b]=sum[z][!b]+abs(a);
         end[x][b]=end[z][!b];
      }
   }
   instk[x][b]=0;
}

void solve() {
   for(int i=2;i<=n;i++) {
      if(!vis[i][0]) dfs(i,0);
      if(!vis[i][1]) dfs(i,1);
   }
   for(int a=1;a<n;a++) {
      int z=1+a;
      if(end[z][1].S<0) {
         cout << -1 << endl;
      } else {
         int z2=end[z][1].F;
         int b2=end[z][1].S;
         if(z2==1) {
            if(b2==0) cout << -1 << endl;
            else {
               // back then 1-a
               long long sol=a+a+sum[z][1];
               cout << sol << endl;
            }
         } else {
            long long sol=a+sum[z][1];
            cout << sol << endl;
         }
      }
   }
}

int main(void) {
   RI(n);
   for(int i=2;i<=n;i++)
      RI(s[i]);
   solve();
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread