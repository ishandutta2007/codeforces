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
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

const double pi=acos(-1.0);

int main(void) {
   double w,h,a;
   scanf("%lf %lf %lf",&w,&h,&a);
   if(a>90.0) a=180.0-a;
   a=a/180.0*pi;
   double d=sqrt(w*w+h*h)*0.5;
   double sol;
   //printf("a=%.4lf %.4lf\n",a,cos(a));
   if((d*d+d*d-min(w,h)*min(w,h))/(2*d*d)<=cos(a)) { // not
      //fprintf(stderr,"!!\n");
      double A=1+cos(a);
      double B=sin(a);
      double x=(A*w-B*h)/(A*A-B*B);
      double y=(A*h-B*w)/(A*A-B*B);
      //printf("%.4lf %.4lf\n",x,y);
      sol=w*h-(x*x+y*y)*sin(a)*cos(a);
   } else { // over
      //fprintf(stderr,"??\n");
      double s=min(w,h);
      double z=s/sin(a);
      sol=z*z*sin(a);
   }
   printf("%.12lf\n",sol);
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread