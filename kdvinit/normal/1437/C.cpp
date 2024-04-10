/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
//#define int long long

int infy=1e5;
int dp[201][401];
int n;

void printit()
{
    cout<<"Hi"<<endl;
    for(int i2=1;i2<=n;i2++)
    {
        for(int j2=1;j2<=2*n;j2++) cout<<dp[i2][j2]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*n;j++) dp[i][j]=infy;
    }

    for(int j=1;j<=2*n;j++)
    {
        dp[1][j]=abs(a[1]-j);
        if(j>1) dp[1][j]=min(dp[1][j],dp[1][j-1]);
    }



    for(int i=2;i<=n;i++)
    {
        for(int j=i;j<=2*n;j++)
        {
            dp[i][j]=dp[i-1][j-1]+abs(a[i]-j);
            if(j>i) dp[i][j]=min(dp[i][j],dp[i][j-1]);
        }
    }

    cout<<dp[n][2*n]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}