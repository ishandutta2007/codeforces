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
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
#define PR printf
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
#define DPRS(x) fprintf(stderr,"<"#x"=%s>\n",x)
#define DPRMSG(x) fprintf(stderr,#x"\n")
#define DPRPII(x) fprintf(stderr,"<"#x"=(%d,%d)>\n",x.F,x.S)
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

#define MAXN 100500
const int inf=100000000;

class Node {
   public:
      int y;
      Node *prev,*next;
      bool bye;
      void erase() {
         prev->next=next;
         next->prev=prev;
         bye=1;
      }
};

int n;
Node s[MAXN];

void prlist() {
   Node *v=s[0].next;
   while(v!=s+n+1) {
      printf(" %d",v->y);
      v=v->next;
   } puts("");
}

int solve() {
   vector<Node*> que[2];
   for(int i=n;i>0;i--) {
      s[i].bye=0;
      que[0].PB(s+i);
   }
   for(int t=0;;t++) {
      //prlist();
      vector<Node*> &cq=que[t&1];
      vector<Node*> &nq=que[t+1&1];
      nq.clear();
      bool upd=0;
      for(int qi=0;qi<cq.size();qi++) {
         Node *v=cq[qi];
         //DPRI(v->y);
         if(v->bye) continue;
         if(v->next->y<v->y) {
            v->next->erase();
            nq.PB(v);
            upd=1;
         }
      }
      if(!upd) return t;
   }
}

int main(void) {
   RI(n);
   s[0].next=s+1;
   s[0].y=inf;
   for(int i=1;i<=n;i++) {
      //RI(s[i]);
      RI(s[i].y);
      s[i].prev=s+i-1;
      s[i].next=s+i+1;
   }
   s[n+1].prev=s+n;
   s[n+1].y=inf;
   PRI(solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread