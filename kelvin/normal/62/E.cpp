#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXR 5
#define MAXC 100050
#define MAXB (1<<MAXR)

int tp[MAXR+1] = {1,2,4,8,16,32};
const long long infll = 10000000000000LL;

int rn,cn;
int hcap[MAXR][MAXC],vcap[MAXR][MAXC];
long long dp[2][MAXB];

inline void relax(long long &x,long long val) { if(val<x) x=val; }
inline bool getbit(int b,int x) { return (b&tp[x])?1:0; }

inline long long solve() {
   int bn=tp[rn];
   int mask=bn-1;
   int ci=0,ni=1;
   dp[0][bn-1]=0;
   for(int b=0;b<bn-1;b++)
      dp[0][b]=infll;
   for(int j=0;j<cn-1;j++) {
      for(int i=0;i<rn;i++) {
         for(int b=0;b<bn;b++)
            dp[ni][b]=infll;
         for(int b=0;b<bn;b++) {
            if(dp[ci][b]>=infll) continue;
            for(int t=0;t<2;t++) {
               int nb;
               long long nc;
               nb=(b<<1)&mask|t;
               nc=dp[ci][b];
               if(i&&t!=getbit(b,0)) nc+=vcap[i-1][j+1];
               if(t!=getbit(b,rn-1)) nc+=hcap[i][j];
               if(i==rn-1&&t!=getbit(b,rn-2)) nc+=vcap[i][j+1];
               relax(dp[ni][nb],nc);
            }
         }
         std::swap(ci,ni);
      }
   }
   return dp[ci][0];
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int j=0;j<cn-1;j++)
      for(int i=0;i<rn;i++)
         scanf("%d",hcap[i]+j);
   for(int j=0;j<cn;j++)
      for(int i=0;i<rn;i++)
         scanf("%d",vcap[i]+j);
   std::cout << solve() << std::endl;
   return 0;
}