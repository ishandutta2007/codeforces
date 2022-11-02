#include <stdio.h>
#define MAXVAL 100050

int a,b,m,x0;
bool vis[MAXVAL]={0};
int ts[MAXVAL];

inline int f(int x) {
   return (a*x+b)%m;
}

int main(void)
{
   scanf("%d %d %d %d",&a,&b,&m,&x0);
   int x=x0,t=0;
   while(!vis[x]) {
      vis[x]=1;
      ts[x]=t++;
      x=f(x);
   }
   printf("%d\n",t-ts[x]);
   return 0;
}