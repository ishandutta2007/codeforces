/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int infy=1e20;
int neg_infy=(-1)*infy;

void solve()
{
    int n,m,k,mx;
    cin>>n>>m>>k;
    mx=m/2;

    int a[n+1][m+1];
    for(int i=1;i<=n;i++) { for(int j=1;j<=m;j++) cin>>a[i][j]; }

    int dp[n+1][m+1][mx+1][k];
    for(int i1=0;i1<=n;i1++)
    {
        for(int i2=0;i2<=m;i2++)
        {
            for(int i3=0;i3<=mx;i3++)
            {
                for(int i4=0;i4<k;i4++)
                {
                    if(i3==0 && i4==0) dp[i1][i2][i3][i4]=0;
                    else dp[i1][i2][i3][i4]=neg_infy;
                }
            }
        }
    }

    for(int i1=1;i1<=n;i1++)
    {
        for(int i2=1;i2<=m;i2++)
        {
            int x=a[i1][i2];

            if(i2==1)
            {
                for(int i4=0;i4<k;i4++)
                {
                    for(int i3=0;i3<=mx;i3++)
                    {
                        dp[i1][i2][0][i4]=max(dp[i1][i2][0][i4],dp[i1-1][m][i3][i4]);
                        if(1<=mx) dp[i1][i2][1][(i4+x)%k]=max(dp[i1][i2][1][(i4+x)%k],dp[i1-1][m][i3][i4]+x);
                    }
                }
                continue;
            }

            for(int i3=0;i3<mx;i3++)
            {
                for(int i4=0;i4<k;i4++)
                {
                    dp[i1][i2][i3+1][(i4+x)%k]=max(dp[i1][i2][i3+1][(i4+x)%k],dp[i1][i2-1][i3][i4]+x);
                }
            }
            for(int i3=0;i3<=mx;i3++)
            {
                for(int i4=0;i4<k;i4++)
                {
                    dp[i1][i2][i3][i4]=max(dp[i1][i2][i3][i4],dp[i1][i2-1][i3][i4]);
                    /*
                    if(dp[i1][i2][i3][i4]<0) cout<<"- ";
                    else cout<<dp[i1][i2][i3][i4]<<" ";
                    */
                }
                //cout<<endl;
            }
            //cout<<endl;
        }
    }

    int ans=0;
    for(int i3=0;i3<=mx;i3++)
    {
        ans=max(ans,dp[n][m][i3][0]);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}