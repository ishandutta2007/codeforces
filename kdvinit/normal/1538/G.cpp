/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int x, y, a, b;

bool check(int k)
{
    int mn = min(a,b);
    int diff = max(a, b) - min(a, b);

    int tx = x, ty = y;
    tx-=(k*mn);
    ty-=(k*mn);

    if(tx<0 || ty<0) return false;

    if(diff==0) return true;

    int cur = (tx/diff) + (ty/diff);

    if(cur>=k) return true;
    else return false;
}

void solve()
{
    cin>>x>>y>>a>>b;

    int l = 0;
    int r = 1e10;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }

    cout<<l<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}