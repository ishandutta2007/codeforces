#include <iostream>

using namespace std;

const int MOD=1000000007;
long long n,a[2000],dp[2000];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[1]=2;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==i) dp[i]=(dp[i-1]+2)%MOD;
        else
            dp[i]=(dp[i-1]+1+dp[i-1]+1-dp[a[i]-1]+MOD)%MOD;
    }
    cout<<dp[n]<<endl;
}