/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 501;

int d[N][N];

int sum(int k)
{
    int ans=0;
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=k; j++) ans+=d[i][j];
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cin>>a[i][j];
    }

    int per[n+1];
    for(int i=n; i>=1; i--)
    {
        int x; cin>>x;
        per[i]=x;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) d[i][j] = a[per[i]][per[j]];
    }

    int ans[n+1];
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
        ans[n+1-k] = sum(k);
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}