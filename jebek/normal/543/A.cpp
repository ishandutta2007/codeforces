#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

long long n,m,b,MOD,a[600],ans,dp[2][600][600];

int main()
{
  ios_base::sync_with_stdio(false);
  cin>>n>>m>>b>>MOD;
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    if(a[i]<=b)
      for(int j=i;j<n;j++)
	dp[1][j][a[i]]=(dp[1][j][a[i]]+1)%MOD;
  for(int i=2;i<=m;i++)
    {
      memset(dp[i&1],0,sizeof dp[i&1]);
      for(int j=0;j<n;j++)
	for(int x=0;x<=b;x++)
	  {
	    dp[i&1][j][x]=(x>=a[j]?dp[!(i&1)][j][x-a[j]]:0)+(j>0?dp[i&1][j-1][x]:0);
	    dp[i&1][j][x]%=MOD;
	    // cout<<i<<" "<<j<<" "<<x<<" "<<dp[i&1][j][x]<<endl;
	  }
    }    
  for(int j=0;j<=b;j++)
    ans=(ans+dp[m&1][n-1][j])%MOD;
  cout<<ans<<endl;
}