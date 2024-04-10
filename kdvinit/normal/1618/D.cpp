/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    int ans=0, mx=0, m=n-2*k;
    map<int, int> f;

    for(int i=1; i<=m; i++) ans+=a[i];
    for(int i=m+1; i<=n; i++) mx = max(mx, ++f[a[i]]);

    if(mx>k) ans+=(mx-k);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}