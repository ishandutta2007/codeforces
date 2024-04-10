/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int x[6], y[6];
    for(int i=1; i<=3; i++) cin>>x[i]>>y[i];

    x[4]=min(x[1], x[2]);
    x[5]=max(x[1], x[2]);
    y[4]=min(y[1], y[2]);
    y[5]=max(y[1], y[2]);

    int ans=abs(x[2]-x[1])+abs(y[2]-y[1]);

    if(x[1]==x[2] && x[3]==x[1] && y[4]<=y[3] && y[3]<=y[5])  ans+=2;
    if(y[1]==y[2] && y[3]==y[1] && x[4]<=x[3] && x[3]<=x[5])  ans+=2;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}