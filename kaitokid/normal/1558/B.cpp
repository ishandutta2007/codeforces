#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[4000009],pr[4000009],mod;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>mod;
    dp[1]=1;
    int sum=1,h=0;
    for(int j=2*1,u=2;j<=n;j+=1,u++)
    {
        pr[j]=(pr[j]+dp[1])%mod;
      if(u*(1+1)<=n)  pr[u*(1+1)]=(pr[u*(1+1)]+mod-dp[1])%mod;
    }
    for(int i=2;i<=n;i++)
    {
        h+=pr[i];
        h%=mod;
        dp[i]=sum+h;
        dp[i]%=mod;
        for(int j=2*i,u=2;j<=n;j+=i,u++)
    {
             pr[j]=(pr[j]+dp[i])%mod;
      if(u*(i+1)<=n)  pr[u*(i+1)]=(pr[u*(i+1)]+mod-dp[i])%mod;

    }
    sum+=dp[i];
    sum%=mod;
    }
    cout<<dp[n];
    return 0;
    }