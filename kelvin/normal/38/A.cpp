#include <stdio.h>
#define MAXN 105

int y[MAXN];

int main(void)
{
   int n,a,b;
   scanf("%d",&n);
   for(int i=1;i<n;i++)
      scanf("%d",y+i);
   scanf("%d %d",&a,&b);
   int s=0;
   for(int i=a;i<b;i++)
      s+=y[i];
   printf("%d\n",s);
}