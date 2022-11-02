#include <stdio.h>

int main(void) {
   int n,m,s;
   while(scanf("%d %d",&n,&m)==2) {
      s=n*(n+1)/2;
      m%=s;
      for(int i=1;i<=n;i++)
         if(m>=i) m-=i;
      printf("%d\n",m);
   }
   return 0;
}