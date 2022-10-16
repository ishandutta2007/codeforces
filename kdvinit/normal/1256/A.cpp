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
    int a,b,n,x;
    cin>>a>>b>>n>>x;

    if(x<=b) { cout<<"YES"<<endl; return; }
    if(x<n) { cout<<"NO"<<endl; return; }
    if( x > ( (n*a) + b )) { cout<<"NO"<<endl; return; }
    if((x%n)>b)  { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}