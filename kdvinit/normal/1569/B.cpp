/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    vector<int> win;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='2') win.push_back(i);
    }

    int m = win.size();
    if(m==1 || m==2) { cout<<"NO"<<endl; return; }

    char ans[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) ans[i][j]='=';
        ans[i][i]='X';
    }

    for(int i=0; i<m; i++)
    {
        int j=(i+1)%m;

        int x = win[i];
        int y = win[j];
        ans[x][y]='+';
        ans[y][x]='-';
    }

    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cout<<ans[i][j];
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}