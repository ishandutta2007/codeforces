/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;cin>>n;
    char a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=2; i<=n; i++) if(a[i]!=a[i-1]) { cout<<i-1<<" "<<i<<endl; return; }
    cout<<-1<<" "<<-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}