#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,a[1000009],dp[4200009];

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        dp[a[i]]=a[i];
    }
    for(int i=0;i<4200000;i++)if(dp[i]==0)dp[i]=-1;
    for(int j=0;j<22;j++)
        for(int i=1;i<4200000;i++)
    {
        if(i&(1<<j))dp[i]=max(dp[i],dp[i^(1<<j)]);
    }

    for(int i=0;i<n;i++)
    {
        int u=(1<<22)-1;
        u^=a[i];
        cout<<dp[u]<<" ";

    }
   return 0;
}