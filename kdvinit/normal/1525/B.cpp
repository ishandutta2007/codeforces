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

    int alr = 1;

    for(int i=1; i<=n; i++)
    {
        if(a[i]!=i) alr=0;
    }

    if(alr==1)
    {
        cout<<0<<endl;
        return;
    }

    if(a[1]==1 || a[n]==n) { cout<<1<<endl; return; }

    if(a[1]==n && a[n]==1) { cout<<3<<endl; return; }

    cout<<2<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}