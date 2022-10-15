/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    int tot=0, r, ask;
    for(int i=0; i<n; i++)
    {
        ask = i^tot;
        cout<<(ask)<<endl;
        cin>>r;
        if(r==1) return;
        tot^=ask;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}