/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, s, b;
    cin>>n>>s>>b;

    int a[n+1]={0};
    for(int i=1; i<=n; i++) cin>>a[i];

    int pre[n+1]={0};
    for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];

    int ans = 1e18;
    for(int i=0; i<=n; i++)
    {
        int tmp = (s+b)*(a[i]-0);
        int sd = (pre[n]-pre[i]) - ((n-i)*a[i]);
        tmp += sd*b;
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