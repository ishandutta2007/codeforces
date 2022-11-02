#include <stdio.h>
#include <algorithm>
#define MAXN 20050

const int inf = 1000000000;

int n;
int s[MAXN];

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   int opt=-inf;
   for(int r=3;r<=n;r++) {
      if(n%r) continue;
      int j=n/r;
      for(int x=0;x<j;x++) {
         int m=0;
         for(int i=0;i<r;i++)
            m+=s[(x+i*j)%n];
         opt=std::max(opt,m);
      }
   }
   printf("%d\n",opt);
   return 0;
}