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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int odd=0;
    for(int i=1; i<=n; i+=2)
    {
        odd=GCD(odd, a[i]);
    }

    for(int i=2; i<=n; i+=2)
    {
        if(a[i]%odd==0) odd=1;
    }

    if(odd!=1) { cout<<odd<<endl; return; }

    int even=0;
    for(int i=2; i<=n; i+=2)
    {
        even=GCD(even, a[i]);
    }

    for(int i=1; i<=n; i+=2)
    {
        if(a[i]%even==0) even=1;
    }

    if(even!=1) { cout<<even<<endl; return; }
    cout<<0<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}