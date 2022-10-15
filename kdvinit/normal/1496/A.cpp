/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    char a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    if(2*k >= n) { cout<<"NO"<<endl; return; }

    for(int i=1;i<=k;i++)
    {
        if(a[i]!=a[n+1-i]) { cout<<"NO"<<endl; return; }
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