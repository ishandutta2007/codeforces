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

const long long inf=2000000000000000002LL;

inline long long mult(long long a,long long b) {
   if(a==0||b==0) return 0;
   if(a>=inf/b) return inf;
   return a*b;
}

inline long long add(long long a,long long b) {
   return min(a+b,inf);
}

inline pair<bool,long long> okay(long long b,long long c) {
   long long l=1;
   long long r=inf;
   while(l+1<r) {
      long long m=(l+r)>>1;
      if(mult(m+b,m)<=c) l=m;
      else r=m;
   }
   bool ok=(mult(l+b,l)==c)&&(l&1)==1;
   return MP(ok,l);
}

int main(void) {
   const int range=50000;
   long long n;
   cin >> n;
   vector<long long> arr;
   for(int k=0;(1LL<<k)-1<=n;k++) {
      /*long double a=1.0;
      long double b=3-(1LL<<k+1);
      long double c=-n;
      long long x=-b/2+sqrt(b*b/4-c);
      for(long long d=-range;d<=range;d++) {
         long long x2=x+d;
         if(x2<=0) continue;
         if(!(x2&1)) continue;
         //long long z=x2*(x2-1)/2+((1LL<<k)-1)*x2;
         long long z=add(mult(x2,x2-1)/2,mult((1LL<<k)-1,x2));
         //if(x2*(x2-1)/2+((1LL<<k)-1)*x2==n) {
         if(z==n) {
            //cout << x2 << endl;
            arr.PB(x2<<k);
         }
      }*/
      long long b=(1LL<<k+1)-3;
      long long c=2*n;
      pair<bool,long long> ret=okay(b,c);
      if(ret.F) arr.PB(ret.S<<k);
   }
   sort(arr.begin(),arr.end());
   arr.resize(unique(arr.begin(),arr.end())-arr.begin());
   for(int i=0;i<arr.size();i++)
      cout << arr[i] << endl;
   if(!arr.size()) puts("-1");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread