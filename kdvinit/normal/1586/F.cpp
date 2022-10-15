/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1005;
int dp[N][N], n, k;

int get(int x, int y)
{
    int ans=0;
    int tx=x, ty=y;
    x--; y--;
    for(int i=1; i<=12; i++)
    {
        int r1 = x%k;
        int r2 = y%k;
        if(r1!=r2) ans=i;
        x/=k;
        y/=k;
    }
    dp[tx][ty]=ans;
    return ans;
}

void solve()
{
    cin>>n>>k;

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++) ans= max(ans, get(i, j));
    }

    cout<<ans<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++) cout<<dp[i][j]<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}