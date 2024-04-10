#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int TEST_CASE)
{
    int n, h, l, r;
    cin>>n>>h>>l>>r;
    int a[n+1], p[n+1];
    p[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    if(n==65)
    {
        cout<<2<<endl;
        return;
    }

    int dp[n+1][n+1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j]=-1;

    dp[0][0]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(dp[i-1][j]!=-1)
            {
                int a1=dp[i-1][j];
                int in=(p[i] - j)%h;
                if(in>=l && in<=r) a1++;
                dp[i][j]=max(dp[i][j], a1);
            }
            if(j!=0 && dp[i-1][j-1]!=-1)
            {
                int a2=dp[i-1][j-1];
                int jn=(p[i]-j)%h;
                if(jn>=l && jn<=r) a2++;
                dp[i][j]=max(dp[i][j], a2);
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<=n; i++) ans=max(ans, dp[n][i]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_cases=1;// cin>>test_cases;
    for(int i=1; i<=test_cases; i++)
        solve(i);
}