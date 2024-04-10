/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    int mx = 100*n + 5;
    int dp[mx+1]={0};
    dp[0]=1;

    int bas = 0;
    int tot = 0;

    for(int i=1; i<=n; i++)
    {
        bas += min(a[i], b[i]);
        int x = abs(a[i]-b[i]);
        tot+=x;

        for(int j=mx; j>=0; j--)
        {
            if(dp[j]==0) continue;
            int j2 = j+x;
            if(j2>mx) continue;
            dp[j2]=1;
        }
    }

    int org=0;
    for(int i=1; i<=n; i++)
    {
        int y = (a[i]*a[i] + b[i]*b[i])*(n-2);
        org+=y;
    }

    int ans = 1e15;
    for(int j=0; j<=mx; j++)
    {
        if(dp[j]==0) continue;

        int s1 = bas+j;
        int s2 = bas+tot-j;

        int tmp = (s1*s1) + (s2*s2) + org;
        ans = min(ans, tmp);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}