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

    int a[n+2];
    for(int i=1; i<=n; i++) cin>>a[i];
    a[0]=0; a[n+1]=0;

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]>a[i-1] && a[i]>a[i+1])
        {
            int mn = max(a[i-1], a[i+1]);
            ans+=(a[i]-mn);
            a[i]=mn;
        }
    }

    for(int i=1; i<=n+1; i++) ans+=abs(a[i]-a[i-1]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}