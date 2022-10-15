/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int dp[n+1][n+1];
    for(int i=1;i<=n;i++) dp[i][i]=a[i];

    for(int l=1;l<=n;l++)
    {
        for(int i=1;i+l<=n;i++)
        {
            dp[i][i+l]=-1;
            int nd=i+l;
            for(int j=i;j<nd;j++)
            {
                if(dp[i][j]==-1 || dp[j+1][nd]==-1 || dp[i][j]!=dp[j+1][nd]) continue;
                dp[i][nd]=dp[i][j]+1;
                break;
            }
        }
    }

    int dp2[n+1][n+1];
    for(int l=0;l<=n;l++)
    {
        for(int i=1;i+l<=n;i++)
        {
            if(dp[i][i+l]!=-1) { dp2[i][i+l]=1; continue; }
            int nd=i+l;
            int val=l+1;
            for(int j=i;j<nd;j++)
            {
                int tmp=dp2[i][j]+dp2[j+1][nd];
                val=min(val,tmp);
            }
            dp2[i][nd]=val;
        }
    }
    cout<<dp2[1][n]<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}