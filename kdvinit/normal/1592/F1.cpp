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

    int a[n+2][m+2];
    memset(a, 0, sizeof(a));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            if(x=='B') a[i][j]=1;
        }
    }

    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            a[i][j] = (a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1])%2;
            cnt+=a[i][j];
        }
    }

    int pos=0;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(a[i][j] && a[i][m] && a[n][j] && a[n][m]) pos=1;
        }
    }

    cnt-=pos;
    cout<<cnt<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}