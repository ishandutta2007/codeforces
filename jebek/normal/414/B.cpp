#include <iostream>

using namespace std;

const long long MOD=1000000007;

long long dp[3000][3000],ans,n,k;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=1;
        for(int j=i;j<=n;j+=i)
        {
            for(int u=2;u<=k;u++)
                dp[j][u]=(dp[j][u]+dp[i][u-1])%MOD;
        }
        ans+=dp[i][k];
        ans=ans%MOD;
    }
    cout<<ans<<endl;
}