/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int x, y;
    cin>>x>>y;

    int z = (x+y);
    if(z%2) { cout<<-1<<" "<<-1<<endl; return; }

    z/=2;
    if(x>=z) x-=z;
    else y-=z;

    cout<<x<<" "<<y<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}