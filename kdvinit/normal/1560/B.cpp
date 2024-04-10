/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a, b, c;
    cin>>a>>b>>c;

    int n = 2*abs(a-b);

    if(a>n || b>n || c>n) { cout<<-1<<endl; return; }
    c+=(n/2);
    if(c>n) c-=n;
    cout<<c<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}