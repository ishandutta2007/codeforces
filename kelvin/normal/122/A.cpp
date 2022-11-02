#include <stdio.h>

inline bool islucky(int x) {
   if(!x) return 0;
   while(x) {
      int d=x%10;
      if(d!=4&&d!=7) return 0;
      x/=10;
   }
   return 1;
}

inline bool solve(int n) {
   for(int i=1;i<=n;i++)
      if(n%i==0&&islucky(i)) return 1;
   return 0;
}

int main(void)
{
   int n;
   scanf("%d",&n);
   puts(solve(n)?"YES":"NO");
}