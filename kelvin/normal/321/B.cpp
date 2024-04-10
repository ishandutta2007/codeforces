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

int an,bn;
vector<int> aa,ad;
vector<int> ba;

inline int sub(int qa,int qd) {
   //DPRII(qa,qd);
   int ret=0,j;
   vector<int> b=ba,tmp;
   tmp.reserve(bn);
   j=0;
   for(int i=0;i<qd;i++) {
      while(j<b.size()&&b[j]<=ad[i]) tmp.PB(b[j++]);
      if(j>=b.size()) return 0;
      j++;
   }
   while(j<b.size()) tmp.PB(b[j++]);
   //DPRMSG(--1--);
   b=tmp;
   tmp.clear();
   if(b.size()<qa) return 0;
   j=b.size()-qa;
   for(int t=0;t<j;t++)
      tmp.PB(b[t]);
   for(int i=0;i<qa;i++) {
      while(j<b.size()&&b[j]<aa[i]) tmp.PB(b[j++]);
      if(j>=b.size()) return 0;
      ret+=b[j]-aa[i];
      j++;
   }
   while(j<b.size()) tmp.PB(b[j++]);
   //DPRMSG(--2--);
   //DPRI(ret);
   b=tmp;
   if(qa>=aa.size()&&qd>=ad.size()) {
      for(int i=0;i<b.size();i++)
         ret+=b[i];
   }
   return ret;
}

int solve() {
   sort(ba.begin(),ba.end());
   sort(ad.begin(),ad.end());
   sort(aa.begin(),aa.end());
   int sol=0;
   for(int qa=0;qa<=aa.size();qa++) {
      for(int qdz=0;qdz<2;qdz++) {
         int qd;
         if(qdz) qd=ad.size();
         else qd=0;
         sol=max(sol,sub(qa,qd));
      }
   }
   return sol;
}

int main(void) {
   char in[30];
   RII(an,bn);
   for(int i=0;i<an;i++) {
      int val;
      RS(in); RI(val);
      if(in[0]=='D') ad.PB(val);
      else aa.PB(val);
   }
   for(int i=0;i<bn;i++) {
      int val;
      RI(val);
      ba.PB(val);
   }
   printf("%d\n",solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread