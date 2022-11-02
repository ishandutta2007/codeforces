#include <stdio.h>

inline bool isp(int x) {
   if(x<=1) return 0;
   for(int i=2;i<x;i++)
      if(x%i==0) return 0;
   return 1;
}

inline bool solve(int a,int b) {
   if(b<=a) return 0;
   if(!isp(a)) return 0;
   if(!isp(b)) return 0;
   for(int i=a+1;i<b;i++)
      if(isp(i)) return 0;
   return 1;
}

int main(void)
{
   int a,b;
   scanf("%d %d",&a,&b);
   puts(solve(a,b)?"YES":"NO");
   return 0;
}