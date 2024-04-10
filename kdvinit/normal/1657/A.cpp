/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int x, y;
    cin>>x>>y;

    if(x==0 && y==0) { cout<<0<<endl; return; }

    int z = (x*x) + (y*y);
    int w = sqrt(z);

    if(w*w == z) cout<<1<<endl;
    else cout<<2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}