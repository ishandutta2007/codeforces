/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, h;
    cin>>n>>h;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    int x = a[n];
    int y = a[n-1];

    int s = x+y;
    int k = (h/s);
    h -= (k*s);

    int ans = 2*k;

    if(h>0) { h-=x; ans++; }
    if(h>0) { h-=y; ans++; }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}