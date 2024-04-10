#include <stdio.h>
#include <algorithm>
#include <iostream>
#define MAXN 100000

using namespace std;

int sn;
long long s[MAXN];

inline void gen() {
   sn=0;
   s[sn++]=4;
   s[sn++]=7;
   for(int t=1;t<10;t++) {
      int tn=sn;
      for(int i=0;i<tn;i++) {
         s[sn++]=s[i]*10+4;
         s[sn++]=s[i]*10+7;
      }
   }
   sort(s,s+sn);
//   for(int i=0;i<sn;i++)
//      printf("%d ",s[i]);
}

inline long long min(long long a,long long b) { return a<b?a:b; }
inline long long max(long long a,long long b) { return a>b?a:b; }

inline long long solve(int x) {
   long long r=0;
   for(int i=0;i<sn;i++) {
      long long p=i?s[i-1]:0;
      r+=max((min(x,s[i])-p),0)*s[i];
   }
   return r;
}

int main(void)
{
   int l,r;
   gen();
   scanf("%d %d",&l,&r);
   long long sol=solve(r)-solve(l-1);
   cout << sol << endl;
   return 0;
}