#include <stdio.h>
#include <algorithm>
#define MAXN 300000

int n;
int s[MAXN];
int dp[3][MAXN];
int prev[3][MAXN],at[3][MAXN];

inline int max(int a,int b) { return a>b?a:b; }

inline void solve() {
   int i,j;
   std::sort(s,s+n);
   dp[0][0]=0.0;
   at[0][0]=0.0;
   for(i=1;i<=n;i++) {
      dp[0][i]=s[i-1]-s[0];
      at[0][i]=s[0]+s[i-1];
   }
   for(int t=1;t<3;t++) {
      dp[t][0]=0.0;
      at[t][0]=0.0;
      prev[t][0]=prev[t-1][0];
      j=0;
      for(i=1;i<=n;i++) {
         //printf("(%d %d) %d %d\n",i,j,max(dp[t-1][j],s[i-1]-s[j]),max(dp[t-1][j+1],s[i-1]-s[j+1]));
         while(j<i-1&&max(dp[t-1][j],s[i-1]-s[j])>=max(dp[t-1][j+1],s[i-1]-s[j+1]))
            j++;
         dp[t][i]=max(dp[t-1][j],s[i-1]-s[j]);
         at[t][i]=s[j]+s[i-1];
         prev[t][i]=j;
         //printf("%d %d: %d %d\n",t,i,dp[t][i],prev[t][i]);
      }
   }
   printf("%.6lf\n",dp[2][n]*0.5);
   i=n;
   for(int t=2;t>=0;t--) {
      printf("%.6lf ",at[t][i]*0.5);
      i=prev[t][i];
   }
   puts("");
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   solve();
   return 0;
}