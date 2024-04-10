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

class Segment {
   public:
      int r1,r2,c1,c2;
      void input() {
         scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
         if(r1>r2) swap(r1,r2);
         if(c1>c2) swap(c1,c2);
      }
};

int rn,cn,k;
vector<Segment> rseg,cseg;

bool cmpr(Segment a,Segment b) {
   if(a.r1!=b.r1) return a.r1<b.r1;
   return a.c1<b.c1;
}
bool cmpc(Segment a,Segment b) {
   if(a.c1!=b.c1) return a.c1<b.c1;
   return a.r1<b.r1;
}

/*inline int calc(const vector<pii> segs) {
   int rb=0,ret=0;
   for(int i=0;i<segs.size();i++) {
      ret+=max(segs[i].S,rb)-max(segs[i].F,rb);
      rb=max(rb,segs[i].S);
   }
   return ret;
}*/

const int inf=1000000500;
inline int cut(vector<pii> segs,int todo=inf) {
   int rb=0,ret=0;
   for(int i=0;i<segs.size();i++) {
      int a=max(segs[i].F,rb)-rb;
      if(ret+a>=todo) {
         return rb+(todo-ret);
      }
      ret+=a;
      rb=max(rb,segs[i].S);
   }
   return ret;
}

inline int getnim(int ans=-1) {
   int nim=0;
   vector<int> rseen,cseen;
   for(int i=0,j=0;i<rseg.size();i=j) {
      vector<pii> segs;
      for(j=i;j<rseg.size()&&rseg[i].r1==rseg[j].r1;j++)
         segs.PB(MP(rseg[j].c1,rseg[j].c2));
      segs.PB(MP(cn,cn));
      //int totl=cn-calc(segs);
      int totl=cut(segs);
      if(ans>=0&&(totl^ans)<totl) {
         int todo=totl-(totl^ans);
         int x=cut(segs,todo);
         printf("%d %d %d %d\n",rseg[i].r1,0,rseg[i].r1,x);
         return -1;
      }
      nim^=totl;
      rseen.PB(rseg[i].r1);
   }
   for(int i=0,j=0;i<cseg.size();i=j) {
      vector<pii> segs;
      for(j=i;j<cseg.size()&&cseg[i].c1==cseg[j].c1;j++)
         segs.PB(MP(cseg[j].r1,cseg[j].r2));
      segs.PB(MP(rn,rn));
      //int totl=rn-calc(segs);
      int totl=cut(segs);
      if(ans>=0&&(totl^ans)<totl) {
         int todo=totl-(totl^ans);
         int x=cut(segs,todo);
         printf("%d %d %d %d\n",0,cseg[i].c1,x,cseg[i].c1);
         return -1;
      }
      nim^=totl;
      cseen.PB(cseg[i].c1);
   }
   if((rn-1-rseen.size())&1) nim^=cn;
   if((cn-1-cseen.size())&1) nim^=rn;
   if(ans>=0&&rseen.size()<rn-1&&(cn^ans)<cn) {
      int todo=cn-(cn^ans);
      int z;
      for(z=1;z<=rseen.size();z++)
         if(rseen[z-1]!=z) break;
      printf("%d %d %d %d\n",z,0,z,todo);
      return -1;
   }
   if(ans>=0&&cseen.size()<cn-1&&(rn^ans)<rn) {
      int todo=rn-(rn^ans);
      int z;
      for(z=1;z<=cseen.size();z++)
         if(cseen[z-1]!=z) break;
      printf("%d %d %d %d\n",0,z,todo,z);
      return -1;
   }
   return nim;
}

bool solve() {
   sort(rseg.begin(),rseg.end(),cmpr);
   sort(cseg.begin(),cseg.end(),cmpc);
   int nim=getnim();
   if(!nim) return 0;
   puts("FIRST");
   getnim(nim);
   return 1;
}

int main(void) {
   scanf("%d %d %d",&rn,&cn,&k);
   for(int i=0;i<k;i++) {
      Segment s;
      s.input();
      if(s.r1==s.r2) rseg.PB(s);
      else cseg.PB(s);
   }
   if(!solve()) puts("SECOND");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread