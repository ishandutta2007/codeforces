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

    int h[n+1];
    for(int i=1; i<=n; i++) cin>>h[i];

    for(int i=1; i<n; i++)
    {
        int y = max( (h[i+1]-k), (int)0);
        m+=(h[i]-y);

        if(m<0) { cout<<"NO"<<endl; return; }
    }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}