/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m, h, v;
    cin>>n>>m>>h;
    v = ((n*m)/2)-h;

    if(n%2==1) h -= (m/2);
    if(m%2==1) v -= (n/2);

    if(h<0 || v<0) { cout<<"NO"<<endl; return; }

    if(h%2==0 && v%2==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}