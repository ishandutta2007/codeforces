/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a, b;
    cin>>a>>b;

    int c = abs(a-b);
    if(c%2==1) { cout<<-1<<endl; return; }

    if(a==0 && b==0) { cout<<0<<endl; return; }

    if(a==b) { cout<<1<<endl; return; }
    
    if(a+b==0) { cout<<1<<endl; return; }

    cout<<2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}