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

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; b[i]=a[i]; }

    sort(b+1, b+n+1);

    int ans;
    if(b[1]==b[2]) ans = b[n];
    else ans = b[1];

    for(int i=1; i<=n; i++)
    {
        if(a[i]==ans) cout<<i<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}