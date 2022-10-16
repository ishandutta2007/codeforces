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
    sort(a+1,a+n+1);

    int ans=0;
    int i;
    int diff=1e10;
    for(i=1; i<=n; i++)
    {
        if(a[i]>0) break;
        ans++;
        if(i==1) continue;
        diff = min(diff, a[i]-a[i-1]);
    }

    if(i!=n+1 && a[i]<=diff) ans++;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}