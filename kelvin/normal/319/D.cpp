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

#define MAXL 50050

const int pr=33333331;

int len,tl;
char s[MAXL],tmp[MAXL];
unsigned long long hs[MAXL];
unsigned long long pp[MAXL];

inline long long hashval(int l,int r) {
   return (hs[r]-hs[l])*pp[len-l];
}
inline bool match(int l1,int r1,int l2,int r2) {
   if(l1<0||r1>len) return 0;
   if(l2<0||r2>len) return 0;
   return hashval(l1,r1)==hashval(l2,r2);
}

inline void recalc() {
   hs[0]=0;
   for(int i=0;i<len;i++)
      hs[i+1]=hs[i]+(s[i]-'a'+1)*pp[i];
}

inline bool check(int d) {
   for(int x=d;x+d<=len;x+=d) {
      int l1=0,u1=d+1;
      while(l1+1<u1) {
         int m=(l1+u1)>>1;
         if(match(x-m,x,x+d-m,x+d)) l1=m;
         else u1=m;
      }
      int l2=0,u2=d+1;
      while(l2+1<u2) {
         int m=(l2+u2)>>1;
         if(match(x,x+m,x+d,x+d+m)) l2=m;
         else u2=m;
      }
      if(l1+l2>=d) return 1;
   }
   return 0;
}

inline void cut(int d) {
   //DPRI(d);
   int cur=0;
   tl=0;
   for(int i=0;i<len;i++) {
      tmp[tl++]=s[i];
      if(tl-d-1>=0&&tmp[tl-1]==tmp[tl-d-1]) cur++;
      else cur=0;
      //DPRI(cur);
      if(cur==d) {
         tl-=d;
         cur-=d;
      }
   }
   tmp[tl]='\0';
   strcpy(s,tmp);
   //DPRS(s);
   len=tl;
   recalc();
}

void solve() {
   pp[0]=1;
   for(int i=0;i<len;i++)
      pp[i+1]=pp[i]*pr;
   recalc();
   for(int d=1;d*2<=len;d++) {
      if(!check(d)) continue;
      cut(d);
   }
   puts(s);
}

int main(void) {
   RS(s);
   len=strlen(s);
   solve();
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread