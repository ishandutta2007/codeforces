#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=998244353;
int n,x;
int dp[509][509];
int c[509][509];
int p[509][509];
int go(int r,int u)
{
    if(r==0)return 1;
    if(u<=0)return 0;
    if(dp[r][u]!=-1)return dp[r][u];
    if(r==1)return 0;
    if(u<=r-1)return p[u][r];
    dp[r][u]=go(r,u-r+1);
    for(int i=1;i<=r;i++)
    {
        dp[r][u]+=(((c[r][i]*1LL*p[r-1][i])%mod)*go(r-i,u-r+1))%mod;
        //cout<<r<<" "<<u<<" "<<i<<" "<<dp[r][u]<<" "<<c[r][i]<<" "<<p[r][i]<<" "<<go(r-i,u-r)<<endl;
        dp[r][u]%=mod;
    }
    //cout<<r<<" "<<u<<" "<<dp[r][u]<<endl;
    return dp[r][u];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
c[1][0]=c[1][1]=1;
for(int i=2;i<=500;i++)
{
    c[i][0]=1;
    for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
}
for(int i=1;i<=500;i++)
{
    p[i][0]=1;
    for(int j=1;j<=500;j++)p[i][j]=(p[i][j-1]*1LL*i)%mod;
}
memset(dp,-1,sizeof dp);
cin>>n>>x;
cout<<go(n,x);
    return 0;
}