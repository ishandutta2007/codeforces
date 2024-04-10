#include <stdio.h>

int main(void)
{
   int n,s[3];
   scanf("%d",&n);
   s[0]=s[1]=s[2]=0;
   for(int i=0;i<n;i++) {
      int x;
      for(int j=0;j<3;j++) {
         scanf("%d",&x);
         s[j]+=x;
      }
   }
   int t;
   for(t=0;t<3;t++)
      if(s[t]) break;
   if(t<3) puts("NO");
   else puts("YES");
   return 0;
}