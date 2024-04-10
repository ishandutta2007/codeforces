/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    a*=d;
    b*=c;

    if(a==b) { cout<<0<<endl; return; }
    if(b!=0 && a%b==0) { cout<<1<<endl; return; }
    if(a!=0 && b%a==0) { cout<<1<<endl; return; }
    cout<<2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}