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

/* LowerConcaveHull: test with CF gym "travel"          *
 * maintain a "concave hull" that support the following *
 * 1. insertion of a line                               *
 * 2. query of height(y) on specific x on the hull      */

/* set as needed */
const long double eps=1e-9;
const long double inf=1e19;

class Segment {
   public:
      long long m,c;
      long double x1,x2; // y=mx+c
      bool flag;
      Segment(long long _m,long long _c,long double _x1=-inf,long double _x2=inf,bool _flag=0)
         :m(_m),c(_c),x1(_x1),x2(_x2),flag(_flag) {}
      long double evaly(long double x) const {
         return m*x+c;
      }
      long long evaly(long long x) const {
         return m*x+c;
      }
      const bool operator<(long double x) const {
         return x2-eps<x;
      }
      const bool operator<(const Segment &b) const {
         if(flag||b.flag) return *this<b.x1;
         return m+eps<b.m;
      }
};

class LowerConcaveHull { // maintain a hull like: \__/
   public:
      set<Segment> hull;
      /* functions */
      long double xintersection(Segment a,Segment b) {
         return (a.c-b.c)/(long double)(b.m-a.m);
      }
      inline set<Segment>::iterator replace(set<Segment> &hull,set<Segment>::iterator it,Segment s) {
         hull.erase(it);
         return hull.insert(s).first;
      }
      void insert(Segment s) { // insert a line and update hull
         set<Segment>::iterator it=hull.find(s);
         // check for same slope
         if(it!=hull.end()) {
            if(it->c>=s.c) return;
            hull.erase(it);
         }
         // check if below whole hull
         it=hull.lower_bound(s);
         if(it!=hull.end()&&s.evaly(it->x1)<=it->evaly(it->x1)+eps) return;
         // update right hull
         while(it!=hull.end()) {
            long double x=xintersection(s,*it);
            if(x>=it->x2-eps) hull.erase(it++);
            else {
               s.x2=x;
               it=replace(hull,it,Segment(it->m,it->c,x,it->x2));
               break;
            }
         }
         // update left hull
         while(it!=hull.begin()) {
            long double x=xintersection(s,*(--it));
            if(x<=it->x1+eps) hull.erase(it++);
            else {
               s.x1=x;
               it=replace(hull,it,Segment(it->m,it->c,it->x1,x));
               break;
            }
         }
         // insert s
         hull.insert(s);
      }
      void insert(long long m,long long c) { insert(Segment(m,c)); }
      long long query(long long x) { // return y @ given x
         set<Segment>::iterator it=hull.lower_bound(Segment(0,0,x,x,1));
         return it->evaly(x);
      }
};

#define MAXN 100500

int n;
int x[MAXN],c[MAXN];
long long dp[MAXN];

long long solve() {
   if(n==1) return 0;
   LowerConcaveHull lch;
   lch.insert(-c[0],0);
   for(int i=1;i<n;i++) {
      dp[i]=lch.query(x[i]);
      lch.insert(-c[i],dp[i]);
      //cout << i << ' ' << dp[i] << endl;
   }
   return -dp[n-1];
}

int main(void) {
   RI(n);
   for(int i=0;i<n;i++)
      RI(x[i]);
   for(int i=0;i<n;i++)
      RI(c[i]);
   cout << solve() << endl;
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread