#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll dp[2003][2003];
ll a[2003],h,n;
int main()
{
ios::sync_with_stdio(0);
cin>>n>>h;
for(int i=0;i<n;i++)cin>>a[i];
dp[0][0]=1;
for(int i=0;i<n;i++)
{
ll l=h-a[i];
if(l<0){cout<<0;return 0;}
dp[i+1][l]=(dp[i+1][l]+dp[i][l])%mod;
if(l>0){dp[i+1][l-1]=(dp[i+1][l-1]+(dp[i][l]*l))%mod;
dp[i+1][l-1]=(dp[i+1][l-1]+(dp[i][l-1]*(l)))%mod;
dp[i+1][l]=(dp[i+1][l]+dp[i][l-1])%mod;
}
}
cout<<dp[n][0];
    return 0;
}