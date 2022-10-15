/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

void Add(int &x, int y)
{
    x+=y;
    x%=mod;
}

void solve()
{
    int n; cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        char op; cin>>op;
        if(op=='+') cin>>a[i];
        else a[i]=-1;
    }

    int dp[n+1][n+1], ans=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==-1) continue;
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;

        for(int j=1; j<=n; j++)
        {
            if(a[j]==-1)
            {
                for(int k=0; k<=n; k++)
                {
                    Add(dp[j][k], dp[j-1][k]);

                    if(k!=0) Add(dp[j][k-1], dp[j-1][k]);
                    else Add(dp[j][k], dp[j-1][k]);
                }
            }
            else if(a[j]>a[i] || (a[j]==a[i] && j>i))
            {
                for(int k=0; k<=n; k++)  dp[j][k] = dp[j-1][k], Add(dp[j][k], dp[j-1][k]);
            }
            else
            {
                for(int k=0; k<=n; k++)
                {
                    if(j!=i) Add(dp[j][k], dp[j-1][k]);
                    if(k!=n)
                    {
                        if(k!=0) Add(dp[j][k+1], dp[j-1][k]);
                        if(k==0 && (j<=i)) Add(dp[j][k+1], dp[j-1][k]);
                    }
                }
            }
        }

        int tmp=0;
        for(int k=1; k<=n; k++) Add(tmp, dp[n][k]);
        tmp*=a[i]; tmp%=mod;
        Add(ans, tmp);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}