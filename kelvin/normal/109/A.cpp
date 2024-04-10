#include <stdio.h>
#include <string.h>

int main(void)
{
   int c4,c7,n;
   while(scanf("%d",&n)==1) {
      for(c7=n/7;c7>=0;c7--)
         if((n-c7*7)%4==0) break;
      if(c7<0) printf("-1\n");
      else {
         c4=(n-c7*7)/4;
         while(c4--)
            printf("4");
         while(c7--)
            printf("7");
         puts("");
      }
   }
   return 0;
}