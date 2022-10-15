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

    int np[n+1]={0};
    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        np[b]=1;
    }

    int u;
    for(int i=1; i<=n; i++) if(np[i]==0) u=i;

    for(int i=1; i<=n; i++)
    {
        if(i!=u) cout<<u<<" "<<i<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}