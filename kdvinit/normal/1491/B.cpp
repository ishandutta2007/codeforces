/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, u, v;
    cin>>n>>u>>v;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int mx=0;
    for(int i=1;i<n;i++)
    {
        int tmp=abs(a[i+1]-a[i]);
        mx=max(mx, tmp);
    }

    int x=min(u, v);

    if(mx>=2) { cout<<0<<endl; return; }
    if(mx==1)
    {
        cout<<x<<endl;
        return;
    }
    if(mx==0)
    {
        cout<<x+v<<endl;
        return;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}