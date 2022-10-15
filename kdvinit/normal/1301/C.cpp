/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int ans=(n*(n+1))/2;

    int n0=n-m;
    int n1=m+1;

    int x=(n0/n1);
    int y=x+1;
    int cnty=(n0%n1);
    int cntx=n1-cnty;

    /*
    cout<<x<<" "<<cntx<<endl;
    cout<<y<<" "<<cnty<<endl<<endl;
    */

    int xx=(x*(x+1))/2;
    xx*=cntx;
    int yy=(y*(y+1))/2;
    yy*=cnty;

    ans-=(xx+yy);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}