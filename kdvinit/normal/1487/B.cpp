/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    if(n%2==0)
    {
        int ans=k%n;
        if(ans==0) ans+=n;

        cout<<ans<<endl;
        return;
    }

    int m=n/2;

    int l=(k-1)/m;
    k+=l;

    int ans=k%n;
    if(ans==0) ans+=n;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}