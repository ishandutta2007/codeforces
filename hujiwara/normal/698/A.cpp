#include <bits/stdc++.h>
using namespace std;

const int INF=10000;

int main()
{
  int n;
  scanf("%d",&n);
  int a[100];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  int dp[3][101];
  dp[0][0]=0;
  dp[1][0]=dp[2][0]=INF;
  for(int i=0;i<n;i++){
    dp[0][i+1]=min(dp[0][i],min(dp[1][i],dp[2][i]))+1;
    if(a[i]==2||a[i]==3){
      dp[1][i+1]=min(dp[0][i],dp[2][i]);
    }
    else{
      dp[1][i+1]=INF;
    }
    if(a[i]==1||a[i]==3){
      dp[2][i+1]=min(dp[0][i],dp[1][i]);
    }
    else{
      dp[2][i+1]=INF;
    }
  }
  printf("%d\n",min(dp[0][n],min(dp[1][n],dp[2][n])));
  return 0;
}