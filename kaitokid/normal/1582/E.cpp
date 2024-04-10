#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100009][509];
ll a[100009],sum[100009];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=n;i>=1;i--)cin>>a[i];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=500;j++)dp[i][j]=-1;
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
      dp[1][1]=a[1];
      dp[1][0]=10000000000;
     for(int i=2;i<=n;i++)
            for(int j=0;j<=500;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(i<j || j==0)continue;
                ll r=sum[i]-sum[i-j];
                if(r<dp[i-j][j-1])dp[i][j]=max(dp[i][j],r);
            }
         int ans;
         for(int i=500;i>0;i--)
         if(dp[n][i]!=-1){ans=i;break;}
         cout<<ans<<endl;
    }
    return 0;
}