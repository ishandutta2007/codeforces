#include <stdio.h>
#include <string.h>
#define MAXL 105
#define MAXCH 55

const int inf=1000000;

int mov[2]={1,-1};

int n,ch;
char s[MAXL];
int dp[MAXL][MAXCH][2];

inline void relax(int &x,int val) { if(val>x) x=val; }
inline int max(int a,int b) { return a>b?a:b; }

inline int solve(int _f) {
   for(int i=0;i<=n;i++)
      for(int c=0;c<=ch;c++)
         for(int f=0;f<2;f++)
            dp[i][c][f]=-inf;
   dp[0][0][_f]=0;
   for(int i=0;i<n;i++) {
      for(int c=0;c<=ch;c++) {
         for(int f=0;f<2;f++) {
            if(dp[i][c][f]<=-inf) continue;
            int cost,x;
            // move forward
            cost=(s[i]=='F'?0:1);
            if(c+cost<=ch) relax(dp[i+1][c+cost][f],dp[i][c][f]+mov[f]);
            // flip
            cost=(s[i]=='T'?0:1);
            if(c+cost<=ch) relax(dp[i+1][c+cost][!f],dp[i][c][f]);
            // do nothing
            if(c+2<=ch) relax(dp[i][c+2][f],dp[i][c][f]);
         }
      }
   }
   return max(dp[n][ch][0],dp[n][ch][1]);
}

int main(void)
{
   scanf("%s",s);
   scanf("%d",&ch);
   n=strlen(s);
   int sol1=solve(0);
   int sol2=solve(1);
   printf("%d\n",max(sol1,sol2));
   return 0;
}