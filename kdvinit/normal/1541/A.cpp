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

    if(n%2==0)
    {
        for(int i=1; i<=n; i+=2) cout<<i+1<<" "<<i<<" ";
        cout<<endl;
    }
    else
    {
        cout<<3<<" "<<1<<" "<<2<<" ";
        for(int i=4; i<=n; i+=2) cout<<i+1<<" "<<i<<" ";
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