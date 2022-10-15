/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int x,y,a,b;
    cin>>x>>y;

    if(x==y) { cout<<x+y<<endl; return; }

    a=max(x,y);
    b=min(x,y);

    a-=b;
    a--;

    int ans=(2*b)+1+(2*a);
    cout<<ans<<endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}