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
#define DPRS(s) fprintf(stderr,"%s\n",#s)
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

#define MAXN 505
#define MAXL 1000
#define ADD 500
#define CMIN 380
#define CMAX 620

inline int dot(pii a,pii b) { return a.F*b.F+a.S*b.S; }

bool inside(pii p) { return p.F>=CMIN-2&&p.F<CMAX+2&&p.S>=CMIN-2&&p.S<CMAX+2; }
bool valid(pii p) { return p.F>=0&&p.F<MAXL&&p.S>=0&&p.S<MAXL; }

#define R 0
#define U 1
#define L 2
#define D 3

const pii adj[4]={MP(1,0),MP(0,1),MP(-1,0),MP(0,-1)};
const char dir[5]="RULD";

int n;
pii apt,bpt;
pii wall[4];
pii pt[MAXN];
bool grid[MAXL][MAXL];

int vis[MAXL][MAXL],visid=0;
vector<int> moves;
vector<char> ans;

#ifndef ONLINE_JUDGE
#include <sys/resource.h>

void increase_stack_size() {
   const rlim_t kStackSize = 32 * 1024 * 1024;  // min stack size = 32 MB
   struct rlimit rl;
   int result;
   result = getrlimit(RLIMIT_STACK, &rl);
   if (result == 0)
   {
      if (rl.rlim_cur < kStackSize)
      {
         rl.rlim_cur = kStackSize;
         result = setrlimit(RLIMIT_STACK, &rl);
         if (result != 0)
         {
            fprintf(stderr, "setrlimit returned result = %d\n", result);
         }
      }
   }
}
#endif

inline void init() {
   ++visid;
   moves.clear();
}
bool rendezvous(pii a,pii des) {
   vis[a.F][a.S]=visid;
   if(a==des) return 1;
   //DPRIII(a.F,a.S,vis[a.F][a.S]);
   for(int i=0;i<4;i++) {
      pii na=a+adj[i];
      if(!inside(na)) continue;
      if(grid[na.F][na.S]) continue;
      if(vis[na.F][na.S]==visid) continue;
      moves.PB(i);
      if(rendezvous(na,des)) return 1;
      moves.POP();
   }
   return 0;
}

/*bool escape(pii a) {
   vis[a.F][a.S]=visid;
   if(!inside(a)) return 1;
   for(int i=0;i<4;i++) {
      pii na=a+adj[i];
      if(inside(na)&&grid[na.F][na.S]) continue;
      if(inside(na)&&vis[na.F][na.S]==visid) continue;
      moves.PB(i);
      if(escape(na)) return 1;
      moves.POP();
   }
   return 0;
}*/

inline void move(int t) {
   pii na=apt+adj[t];
   if(inside(na)&&grid[na.F][na.S]) return;
   ans.PB(t);
   apt=na;
   pii nb=bpt+adj[t];
   if(inside(nb)&&grid[nb.F][nb.S]) return;
   bpt=nb;
}
inline void move(int t,int c) {
   while(c--) move(t);
}
inline void follow() {
   for(int i=0;i<moves.size();i++)
      move(moves[i]);
}
inline void output() {
   for(int i=0;i<ans.size();i++)
      printf("%c",dir[ans[i]]); puts("");
}

bool solve() {
   if(!n) return 0; // intially not at same cell
   for(int t=0;t<4;t++)
      wall[t]=pt[0];
   for(int i=0;i<n;i++)
      for(int t=0;t<4;t++)
         if(dot(pt[i],adj[t])>dot(wall[t],adj[t])) wall[t]=pt[i];
   init();
   if(!rendezvous(apt,bpt)) return false; // not connected
   const pii blnear(CMIN-1,CMIN-1);
   const pii blfar(CMIN>>1,CMIN>>1);
   //const pii blfarther(CMIN/3,CMIN/3);
   init();
   if(rendezvous(apt,blnear)) { // opened maze
      DPRS(wtf);
      follow();
      move(D,blnear.S-blfar.S);
      move(L,blnear.F-blfar.F);
      // if bpt still inside, can safely move to bottom-left
      DPRS(binside);
      if(inside(bpt)) {
         init();
         rendezvous(bpt,blnear);
         follow();
      }
      // now apt,bpt is both outside
      DPRS(2outside);
      while(bpt.F>=CMAX&&bpt.S>=CMIN) move(D);
      while(bpt.S>=CMAX&&bpt.F>=CMIN) move(L);
      while(bpt.F>=CMIN) move(L);
      while(bpt.S>=CMIN) move(D);
      // not both @ bottom-left
      DPRS(last);
      if(apt.F<bpt.F) {
         DPRS(chishi);
         while(bpt.S<wall[L].S) move(U);
         while(apt.F!=bpt.F) move(R);
         while(max(apt.S,bpt.S)>=CMIN) move(D);
      } else if(apt.F>bpt.F) {
         DPRS(chishi2);
         while(bpt.F<=CMAX) move(R);
         while(bpt.S<wall[R].S) move(U);
         while(apt.F!=bpt.F) move(L);
         while(max(apt.S,bpt.S)>=CMIN) move(D);
         while(bpt.F>=CMIN) move(L);
      }
      if(apt.S<bpt.S) {
         DPRS(chishi3);
         while(bpt.F<wall[D].F) move(R);
         while(apt.S!=bpt.S) move(U);
         while(max(apt.F,bpt.F)>=CMIN) move(L);
      } else if(apt.S>bpt.S) {
         DPRS(chishi4);
         while(bpt.S<=CMAX) move(U);
         while(bpt.F<wall[U].F) move(R);
         while(apt.S!=bpt.S) move(D);
         while(max(apt.F,bpt.F)>=CMIN) move(L);
         while(bpt.S>=CMIN) move(D);
      }
      DPRS(bye);
   } else {
      while(apt!=bpt) { // enclosed maze
         init();
         rendezvous(apt,bpt);
         follow();
      }
   }
   assert(apt==bpt);
   output();
   return true;
}

int main(void) {
#ifndef ONLINE_JUDGE
   increase_stack_size();
#endif
   RII(apt.F,apt.S);
   apt.F+=ADD; apt.S+=ADD;
   RII(bpt.F,bpt.S);
   bpt.F+=ADD; bpt.S+=ADD;
   RI(n);
   for(int i=0;i<n;i++) {
      RII(pt[i].F,pt[i].S);
      pt[i].F+=ADD; pt[i].S+=ADD;
      grid[pt[i].F][pt[i].S]=1;
   }
   if(!solve()) puts("-1");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread