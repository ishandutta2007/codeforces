/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int k[n+1],c[m+1];
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    sort(k+1,k+n+1);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=k[i],y=min(n+1-i,m);
        ans+=min(c[x],c[y]);
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