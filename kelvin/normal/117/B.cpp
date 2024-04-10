#include <stdio.h>

int main(void)
{
   int a,b,mod;
   while(scanf("%d %d %d",&a,&b,&mod)==3) {
      if(b>=mod-1) {
         printf("2\n");
         continue;
      }
      int i,m=((-1000000000)%mod+mod)%mod,cur=0;
      bool win=0;
      for(i=0;i<=a&&i<=mod;i++) {
         if(cur>b) {
            win=1;
            break;
         }
         cur+=m;
         if(cur>=mod) cur-=mod;
      }
      if(win) {
         printf("1 %09d\n",i);
      } else {
         printf("2\n");
      }
   }
   return 0;
}