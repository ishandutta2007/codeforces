#include <iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int n,t;
long double p,ans,dp[3000][3000];

int main()
{
    cin>>n>>p>>t;
    dp[0][0]=1;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i+1][j]+=dp[i][j]*(1.0-p);
            dp[i+1][j+1]+=dp[i][j]*p;
        }
        dp[i+1][n]+=dp[i][n];
    }
    for(int i=0;i<=n;i++)
        ans+=(long double)i*dp[t][i];
    cout<<fixed<<setprecision(6)<<ans<<endl;
}