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
    for(int i=1;i<=n;i++) cin>>a[i];

    int ans=0;
    for(int i=1;i<n;i++)
    {
        float x=max(a[i],a[i+1]);
        float y=min(a[i],a[i+1]);

        float z=x/y;

        while(z>2)
        {
            z/=2;
            ans++;
        }
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