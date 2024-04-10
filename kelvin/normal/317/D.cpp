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

const int maxval=1010000000;
//const int maxsqrt=(int)sqrt(maxval)+1;
const int maxsqrt=50000;
const int maxlen=31;

int tp[maxlen];

int n,sqrn,above;
int game[maxlen];
bool vis[maxsqrt];

map<int,int> nim;
const int magic[maxlen]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};

int getnim(int b) {
   if(nim.find(b)==nim.end()) {
      //DPRI(b);
      vector<int> arr;
      arr.reserve(maxlen);
      for(int i=0;i<maxlen&&tp[i]<=b;i++) {
         //DPRI(i);
         if(!(b&tp[i])) continue;
         int nb=b;
         for(int j=i;j<maxlen&&tp[j]<=b;j+=(i+1))
            nb&=(~tp[j]);
         //DPRI(nb);
         int ni=getnim(nb);
         arr.PB(ni);
      }
      sort(arr.begin(),arr.end());
      arr.resize(unique(arr.begin(),arr.end())-arr.begin());
      for(int i=0;i<=arr.size();i++) {
         if(i==arr.size()||arr[i]!=i) {
            nim[b]=i;
            break;
         }
      }
   }
   return nim[b];
}
void pre() {
   for(int i=0;i<maxlen;i++)
      tp[i]=1<<i;
   for(int i=0;i<maxlen;i++) {
      getnim(tp[i]-1);
      //DPRI(getnim(tp[i]-1));
      printf("%d,",getnim(tp[i]-1));
   }puts("");
}

inline void process(int x) {
   if(x==1) {
      vis[1]=1;
      game[1]++;
      return;
   }
   int m=x,c=1;
   vis[x]=1;
   while((long long)m*x<=n) {
      m*=x;
      if(m<=sqrn) vis[m]=1;
      else above--;
      c++;
   }
   DPRII(x,c);
   game[c]++;
}

int solve() {
   //pre();
   //
   sqrn=(int)sqrt(n);
   while(sqrn*sqrn<n) ++sqrn;
   above=n-sqrn;
   for(int x=1;x<=sqrn;x++)
      if(!vis[x]) process(x);
   game[1]+=above;
   //
   int ni=0;
   for(int i=1;i<maxlen;i++) {
      if(!(game[i]&1)) continue;
      //ni^=getnim(tp[i]-1);
      ni^=magic[i];
   }
   return ni;
}

int main(void) {
   RI(n);
   puts(solve()?"Vasya":"Petya");
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread