#include <iostream>

using namespace std;

long long n,dp[20][20];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    cout<<dp[n-1][n-1]<<endl;
}