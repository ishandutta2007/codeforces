/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int b[8];
    for(int i=1; i<=7; i++) cin>>b[i];

    cout<<b[1]<<" "<<b[2]<<" "<<b[7]-b[1]-b[2]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}