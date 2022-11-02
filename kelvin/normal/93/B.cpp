#include <stdio.h>
#define MAXB 55
#define MAXF 55

const double eps=1e-9;

int bn,wt,fn;

inline double min(double a,double b) { return a<b?a:b; }

inline bool sub(bool pflag) {
   int i,j,cc;
   double per,cur,pour,rem;
   if(pflag) puts("YES");
   per=(double)bn*wt/fn;
   j=0;
   cc=0;
   rem=(double)wt;
   for(i=0;i<fn;i++) {
      cur=per;
      while(cur>eps) {
         pour=min(cur,rem);
         if(pflag) printf("%d %.8lf ",j+1,pour);
         cur-=pour;
         rem-=pour;
         cc++;
         if(cc>=3) return 0;
         if(rem<eps) {
            j++;
            cc=0;
            rem=(double)wt;
         }
      }
      if(pflag) puts("");
   }
   return 1;
}

int main(void)
{
   while(scanf("%d %d %d",&bn,&wt,&fn)==3) {
      // wt E (0~1.5xper or =2xper)
      if(sub(0)) sub(1);
      else puts("NO");
   }
   return 0;
}