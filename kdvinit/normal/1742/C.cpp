/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n=8;

    char a[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cin>>a[i][j];
    }

    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        for(int j=1; j<=n; j++)
        {
            if(a[i][j]=='R') cnt++;
        }
        if(cnt==n) { cout<<"R"<<endl; return; }
    }

    cout<<"B"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}