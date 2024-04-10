#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5;
int n,t[maxn],dp[maxn];

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    {
      cin>>t[i];
      dp[i]=dp[i-1]+20;
      int tmp=upper_bound(t+1,t+i,t[i]-90)-t;
      dp[i]=min(dp[tmp-1]+50,dp[i]);
      tmp=upper_bound(t+1,t+i,t[i]-1440)-t;
      dp[i]=min(dp[i],dp[tmp-1]+120);
      cout<<dp[i]-dp[i-1]<<'\n';
    }
}