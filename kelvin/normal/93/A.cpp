#include <stdio.h>

int main(void)
{
   int n,m,a,b;
   int sr1,sc1,sr2,sc2,totr;
   while(scanf("%d %d %d %d",&n,&m,&a,&b)==4) {
      a--;
      b--;
      sr1=a/m;
      sc1=a%m;
      sr2=b/m;
      sc2=b%m;
      totr=(n+m-1)/m;
      if(b==n-1) sc2=m-1;
      if(sr1==sr2) puts("1");
      else if(sc1==0&&sc2==m-1) puts("1");
      else if(sr2==sr1+1) puts("2");
      else if(sc1==sc2+1) puts("2");
      else if(sc1==0) puts("2");
      else if(sc2==m-1) puts("2");
      else puts("3");
   }
   return 0;
}