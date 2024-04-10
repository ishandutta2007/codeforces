/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    int x = GCD(n, 100-n);
    x = 100/x;
    cout<<x<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}