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

    char a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans=0;
    for(int i=2; i<=n; i++)
    {
        if(a[i]!=a[i-1]) ans++;
    }

    if(a[1]=='0' && ans>0) ans--;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}