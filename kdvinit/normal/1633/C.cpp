/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int h1, a1, h2, a2, k, h, a;
    cin>>h1>>a1;
    cin>>h2>>a2;
    cin>>k>>a>>h;

    for(int i=0; i<=k; i++)
    {
        int ch = h1+(i*h);
        int ca = a1+((k-i)*a);
        int r1 = ((h2-1)/ca) + 1;
        int r2 = ((ch-1)/a2) + 1;
        if(r1<=r2) { cout<<"YES"<<endl; return; }
    }

    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}