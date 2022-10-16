#include <iostream>
#define MOD 1000000007
using namespace std;

long long n, d, k, ans, dp[120], dp2[120];

int main()
{
cin>>n>>k>>d;

    for(long long i=1;i<=n;i++)
    {
        if(i<=k)
            dp[i] = 1;
        for(long long j=1;j<=k && j<=i;j++)
        {
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    d--;
    for(long long i=1;i<=n;i++)
    {
        if(i<=d)
            dp2[i] = 1;
        for(long long j=1;j<=d && j<=i;j++)
        {
            dp2[i] += dp2[i-j];
            dp2[i] %= MOD;
        }
    }


    long long ans=(dp[n]-dp2[n])%MOD;
    if(ans<0)ans+=MOD;
    cout<<ans;

    return 0;
}