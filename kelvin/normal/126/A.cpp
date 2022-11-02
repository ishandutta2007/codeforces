#include <stdio.h>

int main(void)
{
   int t1,t2,x1,x2,t;
   long long optc,optd,cc,dd;
   int opty1,opty2;
   while(scanf("%d %d %d %d %d",&t1,&t2,&x1,&x2,&t)==5) {
      if(t1==t2) {
         printf("%d %d\n",x1,x2);
         continue;
      } else if(t1==t) {
         printf("%d %d\n",x1,0);
         continue;
      } else if(t2==t) {
         printf("%d %d\n",0,x2);
         continue;
      }
      optc=t2;
      optd=1;
      opty1=0;
      opty2=x2;
      for(int y1=0;y1<=x1;y1++) {
         long long y2=((long long)(t-t1)*y1+(t2-t-1))/(t2-t);
         if((y1||y2)&&y2<=x2) {
            cc=(long long)t1*y1+t2*y2;
            dd=y1+y2;
            //printf("<%.4lf %.4lf %lld %d %lld>\n",(double)cc/dd,(double)optc/optd,dd,y1,y2);
            if(cc*optd<dd*optc || cc*optd==dd*optc && dd>opty1+opty2) {
               optc=cc;
               optd=dd;
               opty1=y1;
               opty2=y2;
            }
         }
      }
      printf("%d %d\n",opty1,opty2);
   }
   return 0;
}