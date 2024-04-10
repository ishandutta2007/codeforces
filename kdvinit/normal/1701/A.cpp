/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n = 4;

    int sum=0;
    for(int i=1; i<=n; i++) { int x; cin>>x; sum+=x; }

    int ans=0;
    if(sum>0) ans=1;
    if(sum==4) ans=2;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}