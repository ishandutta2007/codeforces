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
    int a,b,c;
    cin>>a>>b>>c;

    int x=min(a,b);
    x=min(x,c);

    int y=(a-x);
    y+=(b-x);
    y+=(c-x);

    if(y==0)
    {
        if(x%3==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        return;
    }

    int z=(y-1)/6;
    if(z>=x) { cout<<"NO"<<endl; return; }

    int w=y%6;
    x-=z;

    if(x%3==1 && w==0) { cout<<"YES"<<endl; return; }
    if(x%3==2 && w==3) { cout<<"YES"<<endl; return; }

    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}