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

const int nil=100000000;

class Node {
   public:
      int vl,vr,d;
      Node *_l,*_r;
      bool z;
      Node(int _vl,int _vr):vl(_vl),vr(_vr) {
         d=nil;
         z=1;
         _l=_r=NULL;
      }
      ~Node() {
         delete _l;
         delete _r;
      }
      Node *left() {
         if(!_l) _l=new Node(vl,(vl+vr)>>1);
         return _l;
      }
      Node *right() {
         if(!_r) _r=new Node(((vl+vr)>>1)+1,vr);
         return _r;
      }
      void down() {
         if(vl==vr||!z) return;
         z=0;
         left()->z=right()->z=1;
         left()->d=right()->d=d;
      }
      void insert(int l,int r,int val) {
         if(vl==l&&vr==r) {
            z=1;
            d=val;
         } else {
            int m=(vl+vr)>>1;
            down();
            if(r<=m) left()->insert(l,r,val);
            else if(l>m) right()->insert(l,r,val);
            else {
               left()->insert(l,m,val);
               right()->insert(m+1,r,val);
            }
         }
      }
      int query(int x) {
         //printf("query %d\n",x);
         if(z) {
            return d;
         } else {
            int m=(vl+vr)>>1;
            if(x<=m) return left()->query(x);
            else return right()->query(x);
         }
      }
};

int n,qn;
int a[MAXN],b[MAXN];

int main(void) {
   RII(n,qn);
   for(int i=1;i<=n;i++)
      RI(a[i]);
   for(int i=1;i<=n;i++)
      RI(b[i]);
   Node seg(0,n);
   for(int qi=0;qi<qn;qi++) {
      //printf("<%d>\n",qi);
      int cmd;
      RI(cmd);
      if(cmd==1) {
         int ai,bi,l;
         RII(ai,bi); RI(l);
         seg.insert(bi,bi+l-1,ai-bi);
      } else {
         int x;
         RI(x);
         int r=seg.query(x);
         //printf("r=%d\n",r);
         if(r==nil) printf("%d\n",b[x]);
         else printf("%d\n",a[x+r]);
      }
   }
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread