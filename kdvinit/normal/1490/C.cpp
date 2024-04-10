/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int x;
    cin>>x;

    int y=0;
    while(1)
    {
        if(y*y*y>=x) break;
        y++;
    }

    for(int i=1;i<=y;i++)
    {
        int z=x-(i*i*i);
        if(z<=0) continue;
        int w = cbrt(z);
        if(z==w*w*w)
        {
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}