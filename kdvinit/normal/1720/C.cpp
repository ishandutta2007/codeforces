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
    int cnt1=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            a[i][j]=(x-'0');
            cnt1+=a[i][j];
        }
    }

    if(cnt1==0) { cout<<0<<endl; return; }

    int mn1=3;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            int a1 = a[i][j];
            int a2 = a[i][j+1];
            int a3 = a[i+1][j];
            int a4 = a[i+1][j+1];

            int tmp = a1+a2+a3+a4;
            if(tmp>0) tmp--;
            mn1 = min(mn1, tmp);

        }
    }

    int ans;

    if(mn1==3) ans = cnt1-3+1;
    if(mn1==2) ans = cnt1-2+1;
    if(mn1==1) ans = cnt1-1+1;
    if(mn1==0) ans = cnt1;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}