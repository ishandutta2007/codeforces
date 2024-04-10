#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod,dp[101][101][101],c[101][101],n,m,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k>>mod;
    if(mod==1){cout<<0;return 0;}
   c[1][0]=c[1][1]=1;
   for(int i=2;i<=100;i++)
   {
       c[i][0]=1;
       for(int j=0;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;}

dp[1][1][1]=dp[0][1][0]=1;
for(int i=2;i<=100;i++)dp[1][i][0]=dp[0][i][0]=1;
int g=1;
for(int i=2;i<=n;i++)
  {
      g=(g*1LL*i)%mod;
      dp[i][1][1]=g;


    for(int j=2;j<=min(m,i);j++){
        for(int q=0;q<=i;q++)
{

        for(int d=0;d<i;d++)
            for(int r=0;r<=q;r++)
        {
         int v=(dp[d][j-1][r]*1LL*dp[i-d-1][j-1][q-r])%mod;
          v=(c[i-1][d]*1LL*v)%mod;
          dp[i][j][q]=(dp[i][j][q]+v)%mod;

        }
        if(q>4 &&dp[i][j][q]==0 && dp[i][j][q-1]==0 && dp[i][j][q-2]==0)break;
}
  }
  for(int j=i+1;j<=n;j++)dp[i][j][0]=g;
  }
  cout<<dp[n][m][k];
    return 0;
}