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
    int a[9][9];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char x; cin>>x;
            if(x=='.') a[i][j]=0;
            else a[i][j]=1;
        }
    }

    for(int i=2; i<n; i++)
    {
        for(int j=2; j<n; j++)
        {
            if(a[i][j]+a[i-1][j-1]+a[i-1][j+1]==3) { cout<<i<<" "<<j<<endl; return; }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}