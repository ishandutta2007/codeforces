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

    int a[n+1], b[n+1], pa[n+1]={0}, pb[n+1]={0};
    for(int i=1; i<=n; i++) { cin>>a[i]; pa[i]=a[i] + pa[i-1]; }
    for(int i=1; i<=n; i++) { cin>>b[i]; pb[i]=b[i] + pb[i-1]; }

    int ans = 1e18;
    for(int i=1; i<=n; i++)
    {
        int x = pa[n]-pa[i];
        int y = pb[i-1];
        int tmp = max(x, y);
        ans = min(ans, tmp);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}