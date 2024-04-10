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
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            if(x=='.') a[i][j]=0;
            else a[i][j]=1;
        }
    }

    int col[m+1]={0};
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(a[i+1][j]==1 && a[i][j+1]==1) col[j]=1;
        }
    }

    int pc[m+1]={0};
    for(int j=1; j<=m; j++) pc[j]=col[j]+pc[j-1];

    int q; cin>>q;
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        int sum = pc[r-1]-pc[l-1];
        if(sum==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}