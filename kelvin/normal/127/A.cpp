#include <stdio.h>
#include <math.h>

inline double sq(double x) { return x*x; }

int main(void)
{
   int n,k;
   double l=0.0,t=0.0;
   double x,y,px,py;
   scanf("%d %d",&n,&k);
   scanf("%lf%lf",&px,&py);
   for(int i=1;i<n;i++) {
      scanf("%lf%lf",&x,&y);
      l+=sqrt(sq(x-px)+sq(y-py));
      px=x;
      py=y;
   }
   t=l*k/50;
   printf("%.10lf\n",t);
}