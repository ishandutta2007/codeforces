/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k1, k2;
    cin>>n>>k1>>k2;

    int w, b;
    cin>>w>>b;

    int W = (k1+k2)/2;
    int B = (n-k1 + n-k2)/2;

    if(w<=W && b<=B) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}