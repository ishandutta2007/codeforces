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

#define MAXN 5050
#define MAXVAL 1000050

//int alim[5]={0,1,3,6,10};
int elim[5]={0,2,4,6,8};

int n,rem;
int s[MAXN];
int concnt[MAXVAL];
vector<pii> con[MAXVAL];
int vis[MAXVAL],visid=0;

int cal[MAXVAL];
bool easytest(int m) {
   for(int i=0;i<m;i++)
      cal[i]=0;
   for(int i=0;i<n;i++)
      cal[s[i]%m]++;
   int z=0;
   for(int i=0;i<m;i++)
      z+=max(0,cal[i]-1);
   return z<=rem;
}

int solve() {
   sort(s,s+n);
   for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
         concnt[abs(s[i]-s[j])]++;
         //pii x=MP(i,j);
         //con[abs(s[i]-s[j])].PB(MP(i,j));
      }
   }
   for(int i=0;i<MAXVAL;i++)
      con[i].reserve(concnt[i]);
   for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
         con[abs(s[i]-s[j])].PB(MP(i,j));
   int en;
   int ele[50];
   //puts("start");
   for(int m=1;m<MAXVAL;m++) {
      if(m<10) {
         if(easytest(m)) return m;
         else continue;
      }
      ///if(m==10) puts("m>=100");
      en=0;
      ++visid;
      bool fail=0;
      for(int x=m;x<MAXVAL;x+=m) {
         /*if(arr.size()+con[x].size()>alim[rem]) {
            fail=1;
            break;
         }*/
         for(int i=0;i<con[x].size();i++) {
            if(vis[con[x][i].F]<visid) {
               vis[con[x][i].F]=visid;
               ele[en++]=con[x][i].F;
            }
            if(en>2*rem) {
               fail=1; break;
            }
            if(vis[con[x][i].S]<visid) {
               vis[con[x][i].S]=visid;
               ele[en++]=con[x][i].S;
            }
            if(en>2*rem) {
               fail=1; break;
            }
         }
         if(fail) break;
      }
      if(fail) continue;
      ++visid;
      int mc=0;
      for(int i=0;i<en;i++) {
         int r=s[ele[i]]%m;
         if(vis[r]<visid) {
            vis[r]=visid;
            mc++;
         }
      }
      int cut=en-mc;
      if(cut<=rem) return m;
   }
   return -1;
}

int main(void) {
   RII(n,rem);
   for(int i=0;i<n;i++)
      RI(s[i]);
   printf("%d\n",solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread