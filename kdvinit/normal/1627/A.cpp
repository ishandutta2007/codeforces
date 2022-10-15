/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m, r, c;
    cin>>n>>m>>r>>c;

    int cntb=0, m0=0, m1=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            if(x=='W') continue;
            cntb++;
            if(i==r || j==c) m1=1;
            if(i==r && j==c) m0=1;
        }
    }

    if(cntb==0) { cout<<-1<<endl; return; }
    if(m0) { cout<<0<<endl; return; }
    if(m1) { cout<<1<<endl; return; }
    cout<<2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}