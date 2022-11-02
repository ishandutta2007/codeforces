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

#define MAXN 100050

const int per=48;
const int mod=95542721;
// mod-1 = 95542720
// g^a g^3a g^9a g^27a g^81a ... 
// 3^48 = 1 (mod 95542720)

inline int pow3(int x) { return (long long)x*x%mod*x%mod; }

class Node {
   public:
      int vl,vr,dm,msg;
      int sum[per];
      Node *lnode,*rnode;
      Node(int vl,int vr,int *init):vl(vl),vr(vr) {
         dm=msg=0;
         if(vl==vr) {
            sum[0]=init[vl]%mod;
            for(int i=1;i<per;i++)
               sum[i]=pow3(sum[i-1]);
            lnode=rnode=NULL;
         } else {
            int m=(vl+vr)/2;
            lnode=new Node(vl,m,init);
            rnode=new Node(m+1,vr,init);
            up();
         }
      }
      ~Node() {
         delete lnode;
         delete rnode;
      }
      void tell(int a) {
         msg=(msg+a)%per;
         dm=(dm+a)%per;
      }
      void down() {
         lnode->tell(msg);
         rnode->tell(msg);
         msg=0;
      }
      void up() {
         for(int i=0;i<per;i++)
            sum[(dm+i)%per]=(lnode->sum[(lnode->dm+i)%per]+rnode->sum[(rnode->dm+i)%per])%mod;
      }
      void triple(int l,int r) {
         if(vl==l&&vr==r) tell(1);
         else {
            int m=(vl+vr)/2;
            down();
            if(r<=m) lnode->triple(l,r);
            else if(l>m) rnode->triple(l,r);
            else {
               lnode->triple(l,m);
               rnode->triple(m+1,r);
            }
            up();
         }
      }
      int asksum(int l,int r) {
         if(vl==l&&vr==r) return sum[dm];
         else {
            int m=(vl+vr)/2;
            down();
            up();
            if(r<=m) return lnode->asksum(l,r);
            else if(l>m) return rnode->asksum(l,r);
            else return (lnode->asksum(l,m)+rnode->asksum(m+1,r))%mod;
         }
      }
};

int n,qn;
int s[MAXN];

int main(void) {
   RI(n);
   for(int i=1;i<=n;i++)
      RI(s[i]);
   RI(qn);
   Node seg(0,n,s);
   for(int qi=0;qi<qn;qi++) {
      int cmd,l,r;
      RIII(cmd,l,r);
      if(cmd==1) PRI(seg.asksum(l,r));
      else seg.triple(l,r);
   }
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread