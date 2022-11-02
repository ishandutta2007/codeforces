#include <stdio.h>

inline int solve(int s) {
   if(s<=10) return 0;
   if(s==20) return 15;
   if(s>21) return 0;
   return 4;
}

int main(void)
{
   int s;
   scanf("%d",&s);
   printf("%d\n",solve(s));
}