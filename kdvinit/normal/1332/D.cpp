/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int k;
    cin>>k;

    int p=1;
    while(p<=k) p*=2;

    cout<<2<<" "<<3<<endl;
    cout<<p+k<<" "<<p<<" "<<p<<endl;
    cout<<k<<" "<<p+k<<" "<<k<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}