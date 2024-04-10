#include <stdio.h>

inline int min(int a,int b) { return a<b?a:b; }

int main(void)
{
   int n,a,b;
   scanf("%d %d %d",&n,&a,&b);
   printf("%d\n",min(n-a,b+1));
}