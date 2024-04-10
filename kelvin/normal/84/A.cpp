#include <stdio.h>

inline int max(int a,int b) { return a>b?a:b; }

int main(void)
{
   int n,s=0;
   scanf("%d",&n);
   printf("%d\n",n/2*3);
}