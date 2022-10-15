/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    double ans = 0;
    for(int i=1; i<n; i++) ans+=a[i];
    ans/=(n-1);

    ans+=a[n];
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    std::cout << std::setprecision(15); std::cout << std::fixed;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}