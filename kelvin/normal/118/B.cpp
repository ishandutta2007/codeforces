#include <stdio.h>

inline int abs(int x) { return x<0?-x:x; }

int main(void)
{
   int n;
   scanf("%d",&n);
   for(int i=0;i<(n*2+1)*2-1;i++) {
      if(i&1) continue;
      for(int j=0;j<(2*n+1)*2-1;j++) {
         //printf(",");
         if((i&1)||(j&1)) {
            printf(" ");
            continue;
         }
         int r=i/2,c=j/2;
         int d=abs(r-n)+abs(c-n);
         if(d>n) {
            printf(" ");
            continue;
         }
         printf("%d",n-d);
         if(n==d&&c>=n) break;
      }
      puts("");
   }
   return 0;
}