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
    int n,x;
    cin>>n>>x;

    if(n<=2) cout<<1<<endl;
    else
    {
        n-=2;
        n=(n+x-1)/x;
        n++;
        cout<<n<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}