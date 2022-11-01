#include <iostream>
#include<algorithm>

using namespace std;

const int MOD=1000000007;
long long n,a[600],dp[600][600];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
        dp[i][i]=1;
    for(int j=1;j<n;j++)
        for(int i=1;i+j<n;i++)
        {
            dp[i][i+j]=dp[i+1][i+j];
            if(a[i]<a[i+1])
                dp[i][i+j]=(2*dp[i][i+j])%MOD;
            for(int x=i+2;x<=i+j;x++)
                if(a[x]>a[i])
                    dp[i][i+j]=(dp[i][i+j]+dp[i+1][x-1]*dp[x][i+j])%MOD;
        }
    cout<<dp[1][n-1]<<endl;
}