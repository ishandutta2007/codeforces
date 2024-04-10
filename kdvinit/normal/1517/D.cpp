/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    int incj[n+1][m];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m-1; j++) cin>>incj[i][j];
    }

    int inci[n][m+1];
    for(int i=1; i<=n-1; i++)
    {
        for(int j=1; j<=m; j++) cin>>inci[i][j];
    }

    if(k%2==1)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++) cout<<-1<<" ";
            cout<<endl;
        }

        return;
    }

    k/=2;

    int ans[n+1][m+1][k+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) ans[i][j][0]=0;
    }

    for(int steps=1; steps<=k; steps++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                int tmp = 1e10;

                if(i!=n) tmp = min(tmp, 2*inci[i][j] + ans[i+1][j][steps-1]);
                if(i!=1) tmp = min(tmp, 2*inci[i-1][j] + ans[i-1][j][steps-1]);
                if(j!=m) tmp = min(tmp, 2*incj[i][j] + ans[i][j+1][steps-1]);
                if(j!=1) tmp = min(tmp, 2*incj[i][j-1] + ans[i][j-1][steps-1]);

                ans[i][j][steps]=tmp;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cout<<ans[i][j][k]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}