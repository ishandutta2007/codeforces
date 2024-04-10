/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int l, r;
    cin>>l>>r;

    int ans = r-l;
    int lst=1;
    for(int i=1; i<=10; i++)
    {
        lst*=10;
        int x = l/lst;
        int y = r/lst;
        ans+=(y-x);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}