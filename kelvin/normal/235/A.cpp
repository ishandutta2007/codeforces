#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXVAL 1000500

using namespace std;

int pn,pr[MAXVAL];
int fac[MAXVAL];

int n;
//bool kill[MAXVAL];
long long sol=0;

void gen() {
   pn=0;
   for(int i=3;i<MAXVAL;i+=2) {
      if(fac[i]) {
         fac[i]=i;
         continue;
      }
      pr[pn++]=i;
      if((long long)i*i>=MAXVAL) continue;
      for(int j=i*i;j<MAXVAL;j+=i)
         fac[j]=i;
   }
}

inline long long gcd(long long a,long long b) {
   while(b) {
      long long t=b;
      b=a%b;
      a=t;
   }
   return a;
}
inline long long lcm(long long a,long long b) {
   return a*b/gcd(a,b);
}
inline long long lcm(long long a,long long b,long long c) {
   return lcm(a,lcm(b,c));
}

long long solve() {
   if(n==1) return 1;
   if(n==2) return 2;
   if(n==3) return 6;
   if(n==4) return 12;
   //dfs(0,1);
   if(n&1) return (long long)n*(n-1)*(n-2);
   sol=max((long long)n*(n-1)*(n-2)/2,(long long)(n-1)*(n-2)*(n-3));
   long long thr=(long long)(n-1)*(n-2)*(n-3);
   // n n-1 *
   for(int i=n-2;i>=1;i--)  {
      if((long long)n*(n-1)*i<=thr) break;
      sol=max(sol,lcm(n,n-1,i));
   }
   // n n-2 *
   for(int i=n-3;i>=1;i--)  {
      if((long long)n*(n-2)*i<=thr) break;
      sol=max(sol,lcm(n,n-2,i));
   }
   return sol;
}

int main(void)
{
   //gen();
   scanf("%d",&n);
   cout << solve() << endl;
   return 0;
}