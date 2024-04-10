/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int infy=1e30;

void solve()
{
    int x,y,c[8],ax,ay;
    cin>>x>>y;
    ax=abs(x);
    ay=abs(y);

    for(int i=1;i<=6;i++) cin>>c[i];
    c[7]=c[1]; c[0]=c[6];
    for(int i=1;i<=6;i++) c[i]=min(c[i],c[i-1]+c[i+1]);

    int ans;

    if(x>=0 && y>=0)
    {
        if(ax>ay) ans=( (ax-ay)*c[6] ) + (ay*c[1]);
        else ans=(ax*c[1]) + ( (ay-ax)*c[2] );
    }
    if(x>=0 && y<0) ans=(ax*c[6]) + (ay*c[5]);
    if(x<0 && y>=0) ans=(ax*c[3]) + (ay*c[2]);
    if(x<0 && y<0)
    {
        if(ax>ay) ans=( (ax-ay)*c[3] ) + (ay*c[4]);
        else ans=(ax*c[4]) + ( (ay-ax)*c[5] );
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}