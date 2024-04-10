/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    int mn[2*n+1];
    for(int i=1; i<=n; i++) mn[a[i]]=i;
    for(int i=3; i<=(2*n); i+=2) mn[i] = min(mn[i], mn[i-2]);

    int ans = 10*n;
    for(int i=1; i<=n; i++)
    {
        int tmp = (i-1)+mn[b[i]-1]-1;
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