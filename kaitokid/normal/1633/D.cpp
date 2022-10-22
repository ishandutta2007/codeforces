#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pp[2009],n,k,b[2009],c[2009],dp[1009][12009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pp[1]=0;
    for(int i=2;i<1002;i++)pp[i]=INT_MAX;
    for(int i=1;i<=1000;i++)
       for(int j=1;j<=i;j++)pp[i+i/j]=min(pp[i+i/j],pp[i]+1);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int sum=0;
        for(int i=1;i<=n;i++){cin>>b[i];b[i]=pp[b[i]];}
        for(int i=1;i<=n;i++){cin>>c[i];sum+=c[i];}
        if(k>12*n){cout<<sum<<endl;continue;}
        for(int i=1;i<=n;i++)
            for(int j=0;j<=k;j++)dp[i][j]=INT_MIN;

        for(int i=1;i<=n;i++)
            for(int j=0;j<=k;j++)
            {
            dp[i][j]=dp[i-1][j];
            if(j>=b[i])dp[i][j]=max(dp[i][j],dp[i-1][j-b[i]]+c[i]);
            }

       cout<<dp[n][k]<<endl;

    }
    return 0;
}