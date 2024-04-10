#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static int T[100000];
  for(int i=0;i<n;i++){
    scanf("%d",T+i);
  }
  static int dp[100010];
  dp[0]=0;
  for(int i=0;i<n;i++){
    dp[i+1]=dp[i]+20;
    int j=upper_bound(T,T+n,T[i]-90)-T;
    dp[i+1]=min(dp[i+1],dp[j]+50);
    j=upper_bound(T,T+n,T[i]-1440)-T;
    dp[i+1]=min(dp[i+1],dp[j]+120);
  }
  for(int i=0;i<n;i++){
    printf("%d\n",dp[i+1]-dp[i]);
  }
  return 0;
}