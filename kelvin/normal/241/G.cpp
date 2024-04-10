#include <cstdio>

int main(void)
{
   //freopen("g.out","w",stdout);
   int n=500;
   printf("%d\n",n);
   printf("0 500000\n");
   int x=300000;
   for(int r=n-2;r>=1;r--) {
      x+=r;
      printf("%d %d\n",x,r);
      x+=r;
   }
   printf("1000000 1000000\n");
   return 0;
}