/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int ans=0;
    int p10=1;

    for(int i=9; i>=1; i--)
    {
        int x = i;
        if(n<x) x=n;

        ans += (p10*x);
        n-=x;
        if(n==0) break;

        p10*=10;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}