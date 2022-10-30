#include <iostream>
#include<algorithm>

using namespace std;

const int MOD=1000000007;
int n,a,b,k,sum,ans,dp[6000][6000];

int main()
{
    cin>>n>>a>>b>>k;
    a--;
    b--;
    dp[0][a]=1;
    for(int i=1;i<=k;i++)
    {
        sum=dp[i-1][0];
        for(int j=1;j<b;j++)
            sum=(sum+dp[i-1][j])%MOD;
        if(b>0)
        {
            dp[i][b-1]=sum;
            for(int j=b-2;j>-1;j--)
            {
                dp[i][j]=dp[i][j+1];
                if((b-j)%2==0)
                    dp[i][j]=(dp[i][j]-dp[i-1][(b+j)/2]+MOD)%MOD;
            }
        }
        sum=dp[i-1][n-1];
        for(int j=n-2;j>b;j--)
            sum=(sum+dp[i-1][j])%MOD;
        if(b<n-1)
        {
            dp[i][b+1]=sum;
            for(int j=b+2;j<n;j++)
            {
                dp[i][j]=dp[i][j-1];
                if((j-b)%2==0)
                    dp[i][j]=(dp[i][j]-dp[i-1][(b+j)/2]+MOD)%MOD;
            }
        }
        for(int j=0;j<n;j++)
            dp[i][j]=(dp[i][j]-dp[i-1][j]+MOD)%MOD;
    }
    for(int i=0;i<n;i++)
        ans=(ans+dp[k][i])%MOD;
    cout<<ans<<endl;
}