#include<iostream>
#include<algorithm>
using namespace std;

const int MOD=1e9+7;
int n,m,t[2000];
long long ans,dp[2000][2000],DP[2000];
string s[100];

bool ok(int i,int j)
{
  for(int x=0;x<n;x++)
    if(s[x][i]!=s[x][j])
      return false;
  return true;
}

int main()
{
  cin>>m>>n;
  for(int i=0;i<n;i++)
    cin>>s[i];
  for(int j=0;j<m;j++)
   {
     t[j]++;
     for(int i=0;i<j;i++)
       if(ok(i,j))
	 {
	   t[i]++;
	   t[j]--;
	   break;
	 }
   }
  DP[0]=dp[0][0]=1;
  for(int i=1;i<=1000;i++)
    for(int j=1;j<=i;j++)
      {
	dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%MOD;
	DP[i]=(DP[i]+dp[i][j])%MOD;
	//cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
      }
  ans=1;
  for(int i=0;i<m;i++)
    ans=(ans*DP[t[i]])%MOD;
  cout<<ans<<endl;
}