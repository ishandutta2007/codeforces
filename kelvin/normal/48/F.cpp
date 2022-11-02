#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAXN 500050

using namespace std;

const long double eps = 1e-14;
inline long double abs(long double x) { return x>=0.0?x:0.0-x; }
inline bool iszero(long double x) { return abs(x)<eps; }
inline bool isequal(long double a,long double b) { return iszero(a-b); }

class Company {
   public:
      int p,c;
      Company() {}
      Company(int pi,int ci):p(pi),c(ci) {}
      const bool operator<(const Company &b) const {
         return (long long)c*b.p<(long long)b.c*p;
      }
      const bool operator==(const Company &b) const {
         return (long long)c*b.p==(long long)b.c*p;
      }
};

int dayn,n,w;
int pr[MAXN],ic[MAXN],dc[MAXN];
Company s[MAXN];

long long si;
long double sf;

void get(Company *s,int n,int need) {
   int ln,rn;
   if(need==0) return;
   if(n==1) {
      long long q=(long long)need*s[0].c/s[0].p;
      si+=q;
      sf+=(long double)((long long)need*s[0].c-(long long)q*s[0].p)/s[0].p;
      return;
   }
   swap(s[0],s[rand()%n]);
   ln=1;
   for(int i=1;i<n;i++) {
      if(s[i]==s[0]) {
         if(rand()&1) swap(s[ln++],s[i]);
      } else {
         if(s[i]<s[0]) swap(s[ln++],s[i]);
      }
   }
   if(ln==n) {
      swap(s[0],s[--ln]);
   }
   rn=n-ln;
   long long lps=0;
   for(int i=0;i<ln;i++)
      lps+=s[i].p;
   if(need<=lps) {
      get(s,ln,need);
   } else {
      for(int i=0;i<ln;i++) {
         si+=s[i].c;
         need-=s[i].p;
      }
      get(s+ln,rn,need);
   }
}

inline void solve() {
   si=0;
   sf=0.0;
   for(int t=0;t<dayn;t++) {
      for(int i=0;i<n;i++)
         s[i]=Company(pr[i],ic[i]-dc[i]*t);
      get(s,n,w);
   }
}

int main(void)
{
   scanf("%d %d %d",&dayn,&n,&w);
   for(int i=0;i<n;i++)
      scanf("%d",pr+i);
   for(int i=0;i<n;i++)
      scanf("%d",ic+i);
   for(int i=0;i<n;i++)
      scanf("%d",dc+i);
   solve();
   si+=(long long)sf;
   sf-=(long long)sf;
   sf+=si%10;
   si/=10;
   if(si) cout << si;
   cout << showpoint << fixed << setprecision(12) << sf << endl;
   return 0;
}