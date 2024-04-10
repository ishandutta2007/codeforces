/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n; cin>>n;

    cout<<n<<endl;

    for(int i=1; i<=n; i++) cout<<i<<" ";
    cout<<endl;

    for(int j=2; j<=n; j++)
    {
        for(int i=2; i<=j; i++) cout<<i<<" ";
        cout<<1<<" ";
        for(int i=j+1; i<=n; i++) cout<<i<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}