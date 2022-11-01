#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
string s;
int n,m,a[6000],b[6000];
long long dp[5100][5100],dp1[5100],sum,ans;

int main()
{
  cin>>n;
  cin>>s;
  for(int i=0;i<n;i++)
    if(i==0 || s[i]!=s[i-1])
      a[m++]=int(s[i]-'a');
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<26;j++)
	b[j]=-1,dp1[j]=0;
      sum=0;
      if(i==0)
	{
	  for(int j=0;j<m;j++)
	    {
	      if(b[a[j]]==-1)
		dp[i][j]=1;
	      b[a[j]]=0;
	    }
	}
      else
	{
	  for(int j=m-1;j>-1;j--)
	    {
	      if(b[a[j]]!=-1) dp[i][b[a[j]]]=(sum-dp1[a[j]]+MOD)%MOD;
	      b[a[j]]=j;
	      dp1[a[j]]=sum;
	      sum=(sum+dp[i-1][j])%MOD;
	    }
	  for(int j=0;j<26;j++)
	    if(b[j]!=-1)
	      dp[i][b[j]]=(sum-dp1[j]+MOD)%MOD;
	  //	  for(int j=0;j<m;j++)
	  // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	}
    }
  for(int i=0;i<m;i++)
    ans=(ans+dp[n-1][i])%MOD;
  cout<<ans<<endl;
}