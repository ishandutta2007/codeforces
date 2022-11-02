#include <stdio.h>
#define MAXN 100050

int n,m;
int h[MAXN];
int cnt[MAXN+1]={0};

int main(void)
{
   int i;
   m=0;
   scanf("%d",&n);
   for(i=0;i<n;i++) {
      int x;
      scanf("%d",&x);
      h[i]=++cnt[x];
      if(cnt[x]>m) m=cnt[x];
   }
   for(i=1;i<MAXN;i++)
      if(cnt[i]<cnt[i+1]) break;
   if(i<MAXN) puts("-1");
   else {
      printf("%d\n",m);
      for(i=0;i<n;i++)
         printf("%d ",h[i]);puts("");
   }
}