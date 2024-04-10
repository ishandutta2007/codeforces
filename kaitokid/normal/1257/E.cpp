#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[600009][4];
ll k1,k2,k3;
ll l[600009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>k1>>k2>>k3;
    ll x,n=k1+k2+k3;
    for(int i=0;i<k1;i++){cin>>x;l[x]=0;}
    for(int i=0;i<k2;i++){cin>>x;l[x]=1;}
    for(int i=0;i<k3;i++){cin>>x;l[x]=2;}
    for(int i=1;i<=n;i++)
    {
    if(l[i]==0){dp[i][0]=dp[i-1][0];}else dp[i][0]=dp[i-1][0]+1;
    if(l[i]==1)dp[i][1]=min(dp[i-1][0],dp[i-1][1]);else dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
    if(l[i]==2)dp[i][2]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);else dp[i][2]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;


    }
    ll ans=min(dp[n][0],min(dp[n][1],dp[n][2]));
    cout<<ans;
    return 0;
}