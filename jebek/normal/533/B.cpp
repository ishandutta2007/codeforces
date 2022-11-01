#include <iostream>
#include<algorithm>

using namespace std;

const int MAXN=300000;
long long n,par[MAXN],a[MAXN],dp[MAXN][2],dp1;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=-1000000000000;
        cin>>par[i]>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        dp[i][1]=max(dp[i][1],dp[i][0]+a[i]);
        if(i>1)
        {
            dp1=max(dp[par[i]][0]+dp[i][0],dp[par[i]][1]+dp[i][1]);
            dp[par[i]][1]=max(dp[par[i]][1]+dp[i][0],dp[par[i]][0]+dp[i][1]);
            dp[par[i]][0]=dp1;
        }
      //  cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    cout<<max(dp[1][0],dp[1][1])<<endl;
}