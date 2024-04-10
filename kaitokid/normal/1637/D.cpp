#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[109],b[109],pr[109];
ll dp[109][20009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++)pr[i]=pr[i-1]+a[i]+b[i];
        for(int i=0;i<=n+1;i++)
        for(int j=0;j<=10000;j++)dp[i][j]=-1;
        dp[1][0]=0;
        for(int i=1;i<=n;i++)
        for(int j=0;j<=10000;j++)
        {
            if(dp[i][j]==-1)continue;
            ll u=dp[i][j]+2*a[i]*j+2*b[i]*(pr[i-1]-j);
            if(dp[i+1][j+a[i]]==-1 || dp[i+1][j+a[i]]>u)dp[i+1][j+a[i]]=u;
            u=dp[i][j]+2*b[i]*j+2*a[i]*(pr[i-1]-j);
            if(dp[i+1][j+b[i]]==-1 || dp[i+1][j+b[i]]>u)dp[i+1][j+b[i]]=u;

        }
      ll res=LLONG_MAX;
      for(int i=0;i<=10000;i++)
            if(dp[n+1][i]!=-1)res=min(res,dp[n+1][i]);
      for(int i=1;i<=n;i++)
      {
          res+=a[i]*a[i]*(n-1);
          res+=b[i]*b[i]*(n-1);
      }
      cout<<res<<endl;
    }
    return 0;
}