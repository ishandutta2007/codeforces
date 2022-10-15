/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;

    if(a==b) { cout<<0<<endl; return; }
    int diff=abs(a-b);
    diff%=2;

    if(a<b && diff==1) { cout<<1<<endl; return; }
    if(a>b && diff==0) { cout<<1<<endl; return; }

    cout<<2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}