/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[60][60];

bool check(int i, int j)
{
    if(a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1]) return true;
    return false;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=m+1; j++)
        {
            if(i==0 || i==n+1 || j==0 || j==m+1) { a[i][j]=0; continue; }
            cin>>a[i][j];
        }
    }

    vector< array<int, 2> > ans;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==0) continue;
            if(check(i-1, j-1)) { ans.push_back({i-1, j-1}); continue; }
            if(check(i-1, j)) { ans.push_back({i-1, j}); continue; }
            if(check(i, j-1)) { ans.push_back({i, j-1}); continue; }
            if(check(i, j)) { ans.push_back({i, j}); continue; }
            cout<<-1<<endl; return;
        }
    }

    int len = ans.size();
    cout<<len<<endl;
    for(int i=0; i<len; i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}