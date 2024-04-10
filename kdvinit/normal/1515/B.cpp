/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

bool chk_sq(int n)
{
    int m = sqrt(n);
    return n==m*m;
}

void solve()
{
    int n;
    cin>>n;

    if(n%2==0 && chk_sq(n/2)) { cout<<"YES"<<endl; return; }
    if(n%4==0 && chk_sq(n/4)) { cout<<"YES"<<endl; return; }

    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}