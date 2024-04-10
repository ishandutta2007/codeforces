#include <stdio.h>
#include <math.h>
#define MAXN 105
#define MAXM 2050

const double eps=0.0;

int n,depn,depx;
int a,b;

inline double getlogc(int n,int m) {
   int i;
   double p=0.0;
   if(m<0||m>n) return 0.0;
   for(i=0;i<m;i++) {
      p+=log(n-i);
      p-=log(i+1);
   }
   return p;
}

inline double solve() {
   int i;
   double p;
   //printf("<%d %d %d>\n",a,b,n);
   if(a+b<n) return -1.0;
   if(n>b) return 1.0;
   p=getlogc(b,n)-getlogc(a+b,n);
   p=exp(p);
   return 1.0-p;
}

int main(void)
{
   int i,s;
   while(scanf("%d %d %d",&n,&depn,&depx)==3) {
      b=0;
      for(i=1;i<=depn;i++) {
         scanf("%d",&s);
         if(i==depx) a=s-1;
         else b+=s;
      }
      n--;
      printf("%.10lf\n",solve()+eps);
   }
   return 0;
}