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

    if(n%2050!=0) cout<<-1<<endl;
    else
    {
        n/=2050;
        int ans=0;
        while(n!=0)
        {
            ans+=n%10;
            n/=10;
        }
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}