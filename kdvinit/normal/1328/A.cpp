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
    int a,b,c;
    cin>>a>>b;

    if(b>=a) { cout<<b-a<<endl; return; }
    if(a%b==0) { cout<<0<<endl; return; }
    c=a/b;
    c++;
    b*=c;
    b-=a;
    cout<<b<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}