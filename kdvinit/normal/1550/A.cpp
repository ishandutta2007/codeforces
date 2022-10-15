/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int floor_sqrt(int n)       //n>=0
{
    if(n==0) return 0;
    int l=1, r=n+1;
    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if((mid*mid)<=n) l=mid;
        else r=mid;
    }
    return l;
}

void solve()
{
    int n;
    cin>>n;

    int ans = floor_sqrt(n-1)+1;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}