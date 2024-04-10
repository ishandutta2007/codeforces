/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int m = 450;
const int N = 1e5+5;
int dp[N][m+1];

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) { int x; cin>>x; a[n+1-i]=x; }

    int pre[n+1]={0};
    for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
    
    for(int j=1; j<=m; j++) dp[0][j]=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) dp[i][j]=dp[i-1][j];

        dp[i][1] = max(dp[i][1], a[i]);
        for(int l=2; l<=m; l++)
        {
            int j = i-l;
            if(j<1) continue;
            int x = pre[i]-pre[j];
            if(dp[j][l-1]<=x) continue;
            dp[i][l]=max(dp[i][l], x);
        }
    }

    int ans=1;
    for(int i=2; i<=m; i++) if(dp[n][i]!=0) ans=i;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}