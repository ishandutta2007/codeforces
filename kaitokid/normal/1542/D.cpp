#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
char c[509];
ll x[509];
ll dp[509];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

int n;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>c[i];
    if(c[i]=='+')cin>>x[i];
}
ll ans=0;
for(int u=0;u<n;u++)
{
    if(c[u]=='-')continue;
    memset(dp,0,sizeof dp);
    dp[0]=1;
    for(int i=0;i<u;i++)
    {
        if(c[i]=='-')
        {
            dp[0]=(dp[0]*2)%mod;
            for(int j=0;j<=i+1;j++)dp[j]=(dp[j]+dp[j+1])%mod;
            continue;
        }
        if(x[i]>x[u])
        {
            for(int j=0;j<=i+1;j++)dp[j]=(dp[j]*2)%mod;
            continue;
        }
        for(int j=i+1;j>=0;j--)
            dp[j]=(dp[j]+dp[j-1])%mod;
    }
    for(int i=u+1;i<n;i++)
    {
        if(c[i]=='-')
        {
            for(int j=0;j<=i+1;j++)dp[j]=(dp[j]+dp[j+1])%mod;
            continue;
        }
        if(x[i]>=x[u])
        {
            for(int j=0;j<=i+1;j++)dp[j]=(dp[j]*2)%mod;
            continue;
        }
        for(int j=i+1;j>=0;j--)
            dp[j]=(dp[j]+dp[j-1])%mod;
    }
   ll sum=0;
   for(int i=0;i<=n;i++)sum=(sum+dp[i])%mod;
   ans=(ans+((sum*x[u])%mod))%mod;
}
cout<<ans;
    return 0;
}