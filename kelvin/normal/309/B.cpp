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
#define RIII(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x)
#define PRII(x,y) printf("%d %d\n",x,y)
#define DPRI(x) fprintf(stderr,"<"#x"=%d>\n",x)
#define DPRII(x,y) fprintf(stderr,"<"#x"=%d, "#y"=%d>\n",x,y)
#define DPRIII(x,y,z) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d>\n",x,y,z)
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
   T a0=1,a1=0,b0=0,b1=1; if(a<0) { a=-a; a0=-1; } if(b<0) { b=-b; b1=-1; }
   while(b) { T t,q=a/b; t=b; b=a-b*q; a=t; t=b0; b0=a0-b0*q; a0=t; t=b1; b1=a1-b1*q; a1=t; }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define MAXN 1000500
#define MAXL 6000005

int n,rn,cn,totl;
int len[MAXN],suml[MAXN];
char in[MAXL],*word[MAXN];

int reach[MAXN],end[MAXN];
vector<int> rdj[MAXN];
vector<int> stk;
bool vis[MAXN];

inline int lenof(int l,int r) {
   return suml[r+1]-suml[l]+(r-l);
}

void dfs(int v) {
   stk.PB(v);
   end[v]=stk[stk.size()-min((int)stk.size(),rn+1)];
   vis[v]=1;
   for(int i=0;i<rdj[v].size();i++) {
      int u=rdj[v][i];
      if(vis[u]) continue;
      dfs(u);
   }
   stk.POP();
}

void println(int from,int to) {
   for(int i=from;i<to;i++)
      printf("%s%c",word[i],i+1<to?' ':'\n');
}

void solve() {
   suml[0]=0;
   for(int i=0;i<n;i++)
      suml[i+1]=suml[i]+len[i];
   for(int i=0;i<n;i++) {
      if(len[i]>cn) reach[i]=i-1;
      else {
         int j=i?reach[i-1]:0;
         while(j+1<n&&lenof(i,j+1)<=cn) j++;
         reach[i]=j;
      }
      rdj[reach[i]+1].PB(i);
      //DPRII(i,reach[i]);
   }
   reach[n]=n-1;
   for(int i=n;i>=0;i--) {
      if(vis[i]) continue;
      dfs(i);
   }
   pii opt(-1,-1);
   for(int i=0;i<n;i++) {
      int num=end[i]-i;
      opt=max(opt,MP(num,i));
   }
   for(int i=0,x=opt.S;i<rn;i++) {
      println(x,reach[x]+1);
      x=reach[x]+1;
   }
}

int main(void) {
   RIII(n,rn,cn);
   totl=0;
   for(int i=0;i<n;i++) {
      word[i]=in+totl;
      RS(word[i]);
      len[i]=strlen(word[i]);
      totl+=len[i]+1;
   }
   solve();
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread