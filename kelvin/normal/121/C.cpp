#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 1000000

using namespace std;

int sn;
long long s[MAXN];

inline void gen() {
   int pn=0;
   sn=0;
   s[sn++]=4;
   s[sn++]=7;
   for(int t=1;t<10;t++) {
      int tn=sn;
      for(int i=pn;i<tn;i++) {
         s[sn++]=s[i]*10+4;
         s[sn++]=s[i]*10+7;
      }
      pn=tn;
   }
   sort(s,s+sn);
}

int n,k;
const int maxfac=14;

long long fac[18];

inline bool islucky(int x) {
   while(x) {
      int d=x%10;
      if(d!=4&&d!=7) return 0;
      x/=10;
   }
   return 1;
}

inline int solve() {
   int sol=0;
   int ff=(n<maxfac?n:maxfac);
   if(n<=maxfac) {
      long long nnn=1;
      for(int i=1;i<=n;i++)
         nnn*=i;
      if(nnn<k) return -1;
   }
   for(int i=0;i<sn;i++)
      if(s[i]<=n-ff) sol++;
   int b=n-ff+1;
   bool arr[20];
   int last[20];
   memset(arr,0,sizeof(arr));
   k--;
   for(int i=0;i<ff;i++) {
      int x=k/fac[ff-i-1],j;
      for(j=0;;j++) {
         if(arr[j]) continue;
         if(x==0) break;
         x--;
      }
      arr[j]=1;
      last[i]=j;
      k%=fac[ff-i-1];
   }
   for(int i=0;i<ff;i++)
      if(islucky(b+i)&&islucky(b+last[i])) sol++;
   return sol;
}

int main(void)
{
   gen();
   fac[0]=1;
   for(int i=1;i<18;i++)
      fac[i]=fac[i-1]*i;
   scanf("%d %d",&n,&k);
   printf("%d\n",solve());
   return 0;
}