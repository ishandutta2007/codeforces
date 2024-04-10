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

    int a[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin>>a[i][j];
    }

    int ans=0;

    map<int, int> sum, cnt;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x = a[i][j];
            int y = cnt[x]*i - sum[x];
            ans += (y);
            cnt[x]++;
            sum[x]+=i;
        }
    }

    sum.clear();
    cnt.clear();

    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=n; i++)
        {
            int x = a[i][j];
            int y = cnt[x]*j - sum[x];
            ans += (y);
            cnt[x]++;
            sum[x]+=j;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}