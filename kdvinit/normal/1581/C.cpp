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

    int tp[n+2][m+2], lf[n+2][m+2], tl[n+2][m+2];
    memset(tp, 0, sizeof(tp));
    memset(lf, 0, sizeof(lf));
    memset(tl, 0, sizeof(tl));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            a[i][j]=(x-'0');
            tp[i][j]=tp[i-1][j]+a[i][j];
            lf[i][j]=lf[i][j-1]+a[i][j];
            tl[i][j]=tl[i][j-1]+tl[i-1][j]-tl[i-1][j-1]+a[i][j];
        }
    }

    int ans = 1e9;
    for(int i1=1; i1<=n; i1++)
    {
        for(int i2=i1+4; i2<=n; i2++)
        {
            int cost1[m+1], cost2[m+1];
            for(int j=1; j<=m; j++)
            {
                int c1 = (i2-1-i1) - (tp[i2-1][j]-tp[i1][j]);
                int c2 = (j-1) - lf[i1][j-1];
                int c3 = (j-1) - lf[i2][j-1];
                int c4 = tl[i2-1][j-1] - tl[i1][j-1];
                cost1[j] = c2+c3+c4;
                cost2[j] = c1;
            }

            int mn[m+1];
            mn[m] = cost1[m]+cost2[m];

            for(int j=m-1; j>=1; j--) mn[j] = min(mn[j+1], cost1[j]+cost2[j]);

            for(int j1=1; j1+3<=m; j1++)
            {
                int j2 = j1+3;
                int tmp = mn[j2]-cost1[j1+1]+cost2[j1];
                ans = min(ans, tmp);
            }
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