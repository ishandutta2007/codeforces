/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool check(int a, int b, int c)
{
    if(b==c && a%2==0) return true;
    return (a==b+c);
}

void solve()
{
    int a, b, c;
    cin>>a>>b>>c;

    if(check(a, b, c)) { cout<<"YES"<<endl; return; }
    if(check(b, a, c)) { cout<<"YES"<<endl; return; }
    if(check(c, a, b)) { cout<<"YES"<<endl; return; }
    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}