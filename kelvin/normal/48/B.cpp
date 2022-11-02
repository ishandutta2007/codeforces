#include <stdio.h>
#include <algorithm>
#define MAXL 55

int rn,cn,rr,cc;
int g[MAXL][MAXL];
int sum[MAXL][MAXL]={0};

inline void relax(int &x,int val) { if(val<x) x=val; }

inline int get(int r1,int r2,int c1,int c2) {
   return sum[r2+1][c2+1]-sum[r2+1][c1]-sum[r1][c2+1]+sum[r1][c1];
}

inline void pre() {
   for(int i=1;i<=rn;i++)
      for(int j=1;j<=cn;j++)
         sum[i][j]=(sum[i-1][j])+(sum[i][j-1])
                   -(sum[i-1][j-1])+g[i-1][j-1];
}

inline int solve() {
   int opt=rn*cn;
   pre();
   for(int t=0;t<2;t++) {
      for(int i=rr-1;i<rn;i++)
         for(int j=cc-1;j<cn;j++)
            relax(opt,get(i-rr+1,i,j-cc+1,j));
      std::swap(rr,cc);
   }
   return opt;
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         scanf("%d",g[i]+j);
   scanf("%d %d",&rr,&cc);
   printf("%d\n",solve());
   return 0;
}