#include <stdio.h>
#define MAXN 350

int n;
int order[MAXN][MAXN];
int like[MAXN][MAXN];
int time[MAXN];

inline void solve() {
   for(int f=1;f<=n;f++) {
      int opt=MAXN,cl=MAXN,fl=MAXN;
      for(int i=1;i<=n;i++) {
         if(i==f) continue;
         if(like[0][i]<cl) {
            cl=like[0][i];
            fl=like[f][i];
            if(fl<opt) {
               opt=fl;
               time[f]=i;
            }
         }
      }
   }
   for(int i=1;i<=n;i++)
      printf("%d%c",time[i],i<n?' ':'\n');
}

int main(void)
{
   scanf("%d",&n);
   for(int ii=1;ii<=n+1;ii++) {
      int i=ii%(n+1);
      for(int j=1;j<=n;j++) {
         scanf("%d",order[i]+j);
         like[i][order[i][j]]=j;
      }
   }
   solve();
   return 0;
}