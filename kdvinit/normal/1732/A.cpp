/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    int g=0;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        g = GCD(g, x);
    }
    
    if(g==1) { cout<<0<<endl; return; }
    if(GCD(g, n)==1) { cout<<1<<endl; return; }
    if(GCD(g, n-1)==1) { cout<<2<<endl; return; }
    cout<<3<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}