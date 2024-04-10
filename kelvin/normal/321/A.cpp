// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
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

#define MAXL 105
typedef pair<long long,long long> pll;

const int adj[4][2]={1,0,0,1,-1,0,0,-1}; // RULD

int len,x0,y0;
char s[MAXL];

int dx,dy;
int sx[MAXL],sy[MAXL];

inline int c2d(char c) {
   if(c=='R') return 0;
   if(c=='U') return 1;
   if(c=='L') return 2;
   if(c=='D') return 3;
   return -1;
}

inline pll pos(long long t) {
   long long tt=t/len;
   long long tr=t%len;
   return MP(dx*tt+sx[tr],dy*tt+sy[tr]);
}

bool solve() {
   const int tol=100000;
   sx[0]=sy[0]=0;
   for(int i=0;i<len;i++) {
      int z=c2d(s[i]);
      sx[i+1]=sx[i]+adj[z][0];
      sy[i+1]=sy[i]+adj[z][1];
   }
   dx=sx[len];
   dy=sy[len];
   //DPRII(dx,dy);
   if(!dx&&!dy) {
      for(int i=0;i<len;i++)
         if(MP(sx[i],sy[i])==MP(x0,y0)) return 1;
      return 0;
   } else {
      long long t0;
      if(dx) t0=max((long long)x0*len/dx,0LL);
      else t0=max((long long)y0*len/dy,0LL);
      //DPRI(t0);
      for(long long t=max(t0-tol,0LL);t<t0+tol;t++) {
         //DPRII(pos(t).F,pos(t).S);
         if(pos(t)==MP((long long)x0,(long long)y0)) return 1;
      }
      return 0;
   }
}

int main(void) {
   RII(x0,y0);
   RS(s);
   len=strlen(s);
   puts(solve()?"Yes":"No");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread