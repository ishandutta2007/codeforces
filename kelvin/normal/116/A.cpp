#include <stdio.h>

inline int max(int a,int b) { return a>b?a:b; }

int main(void)
{
   int n,s=0,c=0;
   scanf("%d",&n);
   for(int t=0;t<n;t++) {
      int a,b;
      scanf("%d %d",&a,&b);
      s=s-a+b;
      c=max(s,c);
   }
   printf("%d\n",c);
   return 0;
}