/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, x;
    cin>>n>>x;

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; b[i]=a[i]; }

    if(n>=(2*x)) { cout<<"YES"<<endl; return; }

    int r = n-x;
    sort(b+1, b+n+1);

    for(int i=r+1; i+r<=n; i++) if(b[i]!=a[i]) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}