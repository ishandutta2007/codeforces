#include <stdio.h>
#include <algorithm>
#define MAXN 100050

int n;
int s[MAXN];

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   std::sort(s,s+n);
   if(s[n-1]==1) {
      for(int i=0;i<n-1;i++)
         printf("1 ");
      printf("2\n");
      return 0;
   }
   printf("1");
   for(int i=0;i<n-1;i++)
      printf(" %d",s[i]);
   puts("");
   return 0;
}