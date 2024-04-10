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

#define MAXN 2050
const int inf=1000000;

class Segment {
   public:
      int l,r,id;
};

class Node {
   public:
      int vl,vr;
      int cnt,mii;
      pii mil;
      priority_queue<int,vector<int>,greater<int> > pq;
      Node *_l,*_r;
      Node(int vl,int vr):vl(vl),vr(vr) {
         cnt=0;
         mil=MP(inf,-1);
         mii=inf;
         if(vl==vr) pq.push(inf);
         _l=_r=NULL;
      }
      ~Node() {
         delete _l;
         delete _r;
      }
      Node* left() {
         if(!_l) _l=new Node(vl,(vl+vr)/2);
         return _l;
      }
      Node* right() {
         if(!_r) _r=new Node((vl+vr)/2+1,vr);
         return _r;
      }
      void insert(int x,int ind) {
         cnt++;
         mii=min(mii,ind);
         if(vl==vr) {
            if(cnt) mil=MP(vl-cnt,vl);
            else mil=MP(inf,-1);
            pq.push(ind);
         } else {
            int m=(vl+vr)/2;
            if(x<=m) left()->insert(x,ind);
            else right()->insert(x,ind);
            mil=min(left()->mil,right()->mil-MP(left()->cnt,0));
         }
      }
      int getmin(int r) {
         if(r==vr) return mii;
         else {
            int m=(vl+vr)/2;
            if(r<=m) return left()->getmin(r);
            else return min(left()->getmin(m),right()->getmin(r));
         }
      }
      int takemin(int r) {
         return takemin(r,getmin(r));
      }
      int takemin(int r,int minval) {
         cnt--;
         if(vl==vr) {
            int ind=pq.top();
            pq.pop();
            mii=pq.top();
            if(cnt) mil=MP(vl-cnt,vl);
            else mil=MP(inf,-1);
            return ind;
         } else {
            int ret,m=(vl+vr)/2;
            if(r<=m) ret=left()->takemin(r,minval);
            else if(left()->mii==minval) ret=left()->takemin(m,minval);
            else ret=right()->takemin(r,minval);
            mii=min(left()->mii,right()->mii);
            mil=min(left()->mil,right()->mil-MP(left()->cnt,0));
            return ret;
         }
      }
};

int n;
Segment segbyr[MAXN],segbyl[MAXN];
int ans[MAXN],id2ri[MAXN];
bool used[MAXN];

bool cmpr(const Segment &a,const Segment &b) {
   if(a.r!=b.r) return a.r<b.r;
   else return a.l<b.l;
}
bool cmpl(const Segment &a,const Segment &b) {
   return a.l<b.l;
}

bool valid(int thr) {
   //DPRI(thr);
   int sbli=0,sbri=0;
   Node tr(0,n);
   for(int i=0;i<n;i++)
      used[i]=0;
   for(int i=0;i<n;i++) {
      int lb=tr.mil.F;
      int at=tr.mil.S;
      int ind;
      if(lb<i) return 0;
      if(lb>i) {
         while(sbri<n&&used[sbri]) sbri++;
         assert(sbri<n);
         //fprintf(stderr,"!");
         //if(sbli>=n||segbyr[sbri].l<segbyl[sbli].l) ind=tr.takemin(n);
         if(tr.getmin(n)==sbri) ind=tr.takemin(n);
         else ind=sbri;
      } else {
         //fprintf(stderr,"?");
         ind=tr.takemin(at);
      }
      //DPRI(ind);
      ans[i]=segbyr[ind].id;
      used[ind]=1;
      while(sbli<n&&segbyl[sbli].l<=segbyr[ind].r) {
         int u=id2ri[segbyl[sbli++].id];
         if(used[u]) continue;
         tr.insert(i+thr,u);
      }
   }
   return 1;
}

void solve() {
   sort(segbyr,segbyr+n,cmpr);
   sort(segbyl,segbyl+n,cmpl);
   for(int i=0;i<n;i++)
      id2ri[segbyr[i].id]=i;
   //
   int lb=-1,rb=n;
   while(lb<rb-1) {
      int m=(lb+rb)/2;
      if(valid(m)) rb=m;
      else lb=m;
   }
   valid(rb);
   //DPRI(rb);
   for(int i=0;i<n;i++)
      printf("%d%c",ans[i]+1,i+1<n?' ':'\n');
}

int main(void) {
   vector<pii> e;
   RI(n);
   for(int i=0;i<n;i++) {
      RII(segbyr[i].l,segbyr[i].r);
      segbyr[i].id=i;
      segbyl[i]=segbyr[i];
   }
   solve();
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread