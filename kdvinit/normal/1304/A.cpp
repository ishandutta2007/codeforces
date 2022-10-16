/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int x,y,a,b;
    cin>>x>>y>>a>>b;

    y-=x;
    a+=b;
    if(y%a!=0) { cout<<-1<<endl; return; }
    y/=a;
    cout<<y<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}