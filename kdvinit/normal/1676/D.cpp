/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    int c = n+m;

    map<int, int> mps, mpd;

    int a[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            mps[i+j]+=a[i][j];
            mpd[c+i-j]+=a[i][j];
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int tmp = mps[i+j] + mpd[c+i-j] - a[i][j];
            ans = max(ans, tmp);
        }
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