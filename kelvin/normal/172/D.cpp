#include <stdio.h>
#include <iostream>
#define MAXVAL 10000050

using namespace std;

int pn,pr[MAXVAL];
bool np[MAXVAL]={0};

int a,n,ma;
long long s[MAXVAL];

inline void gen() {
   pn=0;
   pr[pn++]=2;
   for(int i=3;i<MAXVAL;i+=2) {
      if(np[i]) continue;
      pr[pn++]=i;
      if(i>4000) continue;
      for(int j=i*i;j<MAXVAL;j+=i)
         np[j]=1;
   }
}

int main(void)
{
   gen();
   scanf("%d %d",&a,&n);
   ma=a+n-1;
   for(int i=a;i<=ma;i++)
      s[i]=1;
   for(int pi=0;pi<pn&&pr[pi]<=ma;pi++) {
      int p=pr[pi];
      bool sg=1;
      for(int q=p;;q*=p) {
         //printf("<%d>\n",q);
         for(int i=(a+q-1)/q*q;i<=ma;i+=q) {
            if(sg) s[i]*=p;
            else s[i]/=p;
         }
         sg=!sg;
         if((long long)q*p>ma) break;
      }
   }
   long long sol=0;
   for(int i=a;i<=ma;i++)
      sol+=s[i];
   cout << sol << endl;
   return 0;
}