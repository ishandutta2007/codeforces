/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

char a[51][51];
int n, m;

bool check(int par)
{
    char b[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if((i+j)%2==par) b[i][j]='R';
            else b[i][j]='W';

            if(a[i][j]=='.') continue;
            if(a[i][j]!=b[i][j]) return false;
        }
    }

    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cout<<b[i][j];
        cout<<endl;
    }

    return true;
}

void solve()
{
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin>>a[i][j];
    }

    if(check(0) || check(1)) return;
    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}