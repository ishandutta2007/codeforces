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
#define MAXL 305000

int n,sol,_sl;
vector<int> adj[MAXN];
char *str[MAXN],_s[MAXL*2];
int strl[MAXN];

char pat[MAXL];
int pre[MAXL],plen;

inline void prekmp(char *p,int pl) {
   int i,x=-1; // match to which position
   pre[0]=-1;
   for(i=1;i<pl;i++) {
      while(x>=0&&p[x+1]!=p[i]) x=pre[x];
      if(p[x+1]==p[i]) x++;
      pre[i]=x;
   }
}
inline int matchkmp(char *s,int sl,char *p,int pl,int x=-1) {
   int i; // match to which position
   for(i=0;i<sl;i++) {
      while(x>=0&&p[x+1]!=s[i]) x=pre[x];
      if(p[x+1]==s[i]) x++;
      //match[i]=x+1;
      if(x+1==pl) {
         sol++;
         x=pre[x];
      }
   }
   return x;
}

void dfs(int v,int x) {
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      int nx=matchkmp(str[u],strl[u],pat,plen,x);
      dfs(u,nx);
   }
}

int solve() {
   plen=strlen(pat);
   prekmp(pat,plen);
   sol=0;
   dfs(1,-1);
   return sol;
}

int main(void) {
   RI(n);
   _sl=0;
   for(int i=2;i<=n;i++) {
      int p;
      RI(p);
      str[i]=_s+_sl;
      RS(str[i]);
      strl[i]=strlen(str[i]);
      str[i][strl[i]]='\0';
      _sl+=strl[i]+1;
      adj[p].PB(i);
   }
   RS(pat);
   cout << solve() << endl;
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread