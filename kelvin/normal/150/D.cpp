#include <stdio.h>
#include <string.h>
#define MAXL 155

const int inf=100000000;

int sl;
char s[MAXL];
int sc[MAXL];
int ac[MAXL][MAXL][MAXL],dp[MAXL][MAXL];

inline void relax(int &x,int val) { if(val>x) x=val; }
inline int getac(int i,int j,int l) { return i==j+1? sc[l]: ac[i][j][l]; }

inline int solve() {
   for(int i=0;i<sl;i++) {
      for(int j=0;j<=sl;j++) {
         for(int l=0;l<=sl;l++)
            ac[i][j][l]=-inf;
         dp[i][j]=0;
      }
   }
   for(int i=0;i<sl;i++) {
      for(int l=0;l<sl;l++) {
         relax(ac[i][i][l],sc[l+1]);
         relax(ac[i][i][l],sc[1]+sc[l]);
      }
      relax(dp[i][i],sc[1]);
   }
   for(int len=2;len<=sl;len++) {
      for(int i=0;i+len<=sl;i++) {
         int j=i+len-1;
         // split
         for(int k=i;k<j;k++)
            relax(dp[i][j],dp[i][k]+dp[k+1][j]);
         for(int l=0;l<=sl-(j-i+1);l++) {
            // use
            for(int t=2;t<=l;t+=2)
               relax(ac[i][j][l],ac[i][j][l-t]+sc[t]);
            // split
            for(int k=i;k<j;k++) {
               relax(ac[i][j][l],ac[i][k][l]+ac[k+1][j][0]);
               relax(ac[i][j][l],ac[i][k][0]+ac[k+1][j][l]);
            }
            // match
            if(s[i]==s[j]) relax(ac[i][j][l],getac(i+1,j-1,l+2));
         }
         relax(dp[i][j],ac[i][j][0]);
      }
   }
   return dp[0][sl-1];
}

int main(void)
{
   scanf("%d",&sl);
   sc[0]=0;
   for(int i=1;i<=sl;i++) {
      scanf("%d",sc+i);
      if(sc[i]<0) sc[i]=-inf;
   }
   scanf("%s",s);
   printf("%d\n",solve());
   return 0;
}