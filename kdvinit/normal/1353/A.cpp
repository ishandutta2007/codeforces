#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    if(n==1) cout<<0<<endl;
    else if(n==2) cout<<m<<endl;
    else cout<<(2*m)<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}