/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    int x = (n-1) + (m-1)*n;
    int y = (m-1) + (n-1)*m;

    int a = min(x, y);
    int b = max(x, y);

    if(a<=k && k<=b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}