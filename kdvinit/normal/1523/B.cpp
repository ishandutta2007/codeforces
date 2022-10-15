#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    cout<<3*n<<endl;

    int m = n/2;
    for(int i=1; i<=m; i++)
    {
        cout<<2<<" "<<i<<" "<<n+1-i<<endl;
        cout<<1<<" "<<i<<" "<<n+1-i<<endl;
        cout<<2<<" "<<i<<" "<<n+1-i<<endl;
        cout<<2<<" "<<i<<" "<<n+1-i<<endl;
        cout<<1<<" "<<i<<" "<<n+1-i<<endl;
        cout<<2<<" "<<i<<" "<<n+1-i<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}