#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n,a[100009],dp[100009][2][2][2][2];
string s;
int main()
{
ios::sync_with_stdio(0);
cin>>n>>s;
memset(dp,-1,sizeof dp);
for(int i=0;i<n;i++)cin>>a[i];
dp[0][0][0][0][0]=0;
for(int i=0;i<n;i++)
{
for(int j=0;j<2;j++)
for(int q=0;q<2;q++)
for(int u=0;u<2;u++)
for(int r=0;r<2;r++)
{
if(dp[i][j][q][u][r]==-1)continue;
if(s[i]!='h'&&s[i]!='a'&&s[i]!='r'&&s[i]!='d')
{dp[i+1][j][q][u][r]=dp[i][j][q][u][r];continue;}
if(s[i]=='h')
{
if(j==1){
if(dp[i+1][j][q][u][r]==-1||dp[i+1][j][q][u][r]>dp[i][j][q][u][r])
dp[i+1][j][q][u][r]=dp[i][j][q][u][r];continue;}
if(dp[i+1][j][q][u][r]==-1||dp[i+1][j][q][u][r]>dp[i][j][q][u][r]+a[i])
dp[i+1][j][q][u][r]=dp[i][j][q][u][r]+a[i];
if(dp[i+1][1][q][u][r]==-1||dp[i+1][1][q][u][r]>dp[i][j][q][u][r])
dp[i+1][1][q][u][r]=dp[i][j][q][u][r];

continue;
}
if(s[i]=='a')
{
if(j==0||q==1){
if(dp[i+1][j][q][u][r]==-1||dp[i+1][j][q][u][r]>dp[i][j][q][u][r])
dp[i+1][j][q][u][r]=dp[i][j][q][u][r];continue;}
if(dp[i+1][j][q][u][r]==-1||dp[i+1][j][q][u][r]>dp[i][j][q][u][r]+a[i])
dp[i+1][j][q][u][r]=dp[i][j][q][u][r]+a[i];
if(dp[i+1][j][1][u][r]==-1||dp[i+1][j][1][u][r]>dp[i][j][q][u][r])
dp[i+1][j][1][u][r]=dp[i][j][q][u][r];
continue;
}
if(s[i]=='r')
{
if(j==0||q==0||u==1){
if(dp[i+1][j][q][u][r]==-1||dp[i+1][j][q][u][r]>dp[i][j][q][u][r])
dp[i+1][j][q][u][r]=dp[i][j][q][u][r];continue;}
if(dp[i+1][j][q][u][r]==-1||dp[i+1][j][q][u][r]>dp[i][j][q][u][r]+a[i])
dp[i+1][j][q][u][r]=dp[i][j][q][u][r]+a[i];
if(dp[i+1][j][q][1][r]==-1||dp[i+1][j][q][1][r]>dp[i][j][q][u][r])
dp[i+1][j][q][1][r]=dp[i][j][q][u][r];
continue;
}
if(s[i]=='d')
{
if(j==0||q==0||u==0||r==1){
if(dp[i+1][j][q][u][r]==-1||dp[i+1][j][q][u][r]>dp[i][j][q][u][r])
dp[i+1][j][q][u][r]=dp[i][j][q][u][r];continue;}
if(dp[i+1][j][q][u][r]==-1||dp[i+1][j][q][u][r]>dp[i][j][q][u][r]+a[i])
dp[i+1][j][q][u][r]=dp[i][j][q][u][r]+a[i];
if(dp[i+1][j][q][u][1]==-1||dp[i+1][j][q][u][1]>dp[i][j][q][u][r])
dp[i+1][j][q][u][1]=dp[i][j][q][u][r];
continue;
}
}



}
ll ans=1000000000000000000;

for(int i=0;i<2;i++)
for(int j=0;j<2;j++)
for(int q=0;q<2;q++)
if(dp[n][i][j][q][0]!=-1)ans=min(ans,dp[n][i][j][q][0]);

cout<<ans;
    return 0;
}