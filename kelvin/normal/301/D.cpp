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

#define MAXN 205000

class BIT {
   public:
      int range;
      long long *dat;
      BIT(int _range):range(_range) {
         dat=new long long[range+1];
         for(int i=0;i<=range;i++)
            dat[i]=0;
      }
      ~BIT() { delete [] dat; }
      void insert(int x,long long a) {
         for(int i=x;i<=range;i+=i&-i) dat[i]+=a;
      }
      long long query(int x) {
         long long r=0;
         for(int i=x;i;i-=i&-i) r+=dat[i];
         return r;
      }
      long long query(int l,int r) {
         l--;
         long long la=l?query(l):0;
         long long ra=r?query(r):0;
         return ra-la;
      }
};

class Query {
   public:
      int l,r,id;
      void input() { RII(l,r); }
      const bool operator<(const Query &b) const { return l>b.l; }
};

int n,qn;
int s[MAXN],pos[MAXN];
Query q[MAXN];
long long ans[MAXN];
vector<int> que[MAXN];

void solve() {
   sort(q,q+qn);
   for(int i=1;i<=n;i++)
      pos[s[i]]=i;
   int qi=0;
   BIT bit(n);
   for(int x=1;x<=n;x++)
      for(int y=x;y<=n;y+=x)
         que[min(pos[x],pos[y])].PB(max(pos[x],pos[y]));
   for(int xi=n;xi>=1;xi--) {
      for(int i=0;i<que[xi].size();i++)
         bit.insert(que[xi][i],1);
      while(qi<qn&&q[qi].l>=xi) {
         ans[q[qi].id]=bit.query(q[qi].l,q[qi].r);
         qi++;
      }
   }
   for(int qi=0;qi<qn;qi++)
      cout << ans[qi] << endl;
}

int main(void) {
   RII(n,qn);
   for(int i=1;i<=n;i++)
      RI(s[i]);
   for(int qi=0;qi<qn;qi++) {
      q[qi].input();
      q[qi].id=qi;
   }
   solve();
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread