#include <bits/stdc++.h>
using namespace std;

const long long INF=10000000000ll;
void up(long long &a,long long b)
{
  if(a>b)a=b;
}

int main()
{
  int n;
  scanf("%d",&n);
  if(n==1){
    printf("0\n");
    return 0;
  }
  vector<long long> a(n);
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }
  bool b=0;
  static long long dp[2][5010][3];
  for(int t=0;t<3;t++){
    dp[b][0][t]=dp[b][1][t]=INF;
  }
  dp[b][0][2]=0;
  dp[b][1][0]=0;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<=(i+1)/2+1;j++){
      dp[!b][j][0]=INF;
      dp[!b][j][1]=INF;
      dp[!b][j][2]=INF;
    }
    for(int j=0;j<=i/2+1;j++){
      //printf("%d %d %lld %lld %lld\n",i,j,dp[b][j][0],dp[b][j][1],dp[b][j][2]);
      up(dp[!b][j][1],dp[b][j][0]+max(0ll,a[i+1]-a[i]+1));
      up(dp[!b][j][2],dp[b][j][2]);
      if(i>0){
	up(dp[!b][j][2],dp[b][j][1]);
	up(dp[!b][j+1][0],dp[b][j][1]+max(0ll,min(a[i],a[i-1]-1)-a[i+1]+1));
      }
      up(dp[!b][j+1][0],dp[b][j][2]+max(0ll,a[i]-a[i+1]+1));
    }
    b=!b;
  }
  long long ans[5010];
  for(int i=1;i<=(n+1)/2;i++){
    ans[i]=min(dp[b][i][0],min(dp[b][i][1],dp[b][i][2]));
  }
  for(int i=(n+1)/2;i-1>0;i--){
    ans[i-1]=min(ans[i-1],ans[i]);
  }
  for(int i=1;i<=(n+1)/2;i++){
    printf("%lld%c",ans[i],i==(n+1)/2?'\n':' ');
  }
  return 0;
}