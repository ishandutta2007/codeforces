#include <stdio.h>
#define MAXL 2050

int n,sol;
char g[MAXL][MAXL];
int rr[MAXL],cc[MAXL],rr2[MAXL],cc2[MAXL];

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline void sub(int m,int *rv=rr,int *cv=cc) {
   for(int i=max(0,m);i<=min(n-1,m+(n-1));i++) {
      int j=i-m;
      g[i][j]^=rv[i]^cv[j];
      if(g[i][j]) {
         //printf("<%d %d>\n",i,j);
         g[i][j]=0;
         sol++;
         rv[i]^=1;
         cv[j]^=1;
         rr2[i]^=1;
         cc2[j]^=1;
      }
   }
}

inline int solve() {
   sol=0;
   for(int i=0;i<n;i++)
      rr2[i]=cc2[i]=rr[i]=cc[i]=0;
   for(int m=1-n;m<0;m++)
      sub(m,rr,cc);
   for(int i=0;i<n;i++)
      rr[i]=cc[i]=0;
   for(int m=n-1;m>0;m--)
      sub(m,rr,cc);
   sub(0,rr2,cc2);
   return sol;
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++) {
      scanf("%s",g[i]);
      for(int j=0;j<n;j++)
         g[i][j]-='0';
   }
   printf("%d\n",solve());
   return 0;
}