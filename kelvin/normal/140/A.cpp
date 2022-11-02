#include <stdio.h>
#include <math.h>

const double eps=1e-9;
const double pi=acos(-1.0);

int main(void)
{
   int n;
   double R,r;
   scanf("%d %lf %lf",&n,&R,&r);
   if(r>R+eps) {
      puts("NO");
      return 0;
   }
   if(r*2>R+eps) {
      if(n<=1) puts("YES");
      else puts("NO");
      return 0;
   }
   if(r*2>=R-eps) {
      if(n<=2) puts("YES");
      else puts("NO");
      return 0;
   }
   double a=asin(r/(R-r));
   int m=(int)(pi/a+eps);
   if(m>=n) puts("YES");
   else puts("NO");
   return 0;
}