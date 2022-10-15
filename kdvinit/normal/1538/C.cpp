/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int pairs(int a[], int n, int r)
{
    int ans = 0, j=n;
    for(int i=1; i<=n; i++)
    {
        while(j!=0 && a[i]+a[j]>r) j--;
        ans+=(j);
        if(2*a[i]<=r) ans--;
    }
    return ans/2;
}

void solve()
{
    int n, l, r;
    cin>>n>>l>>r;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    int ans = pairs(a, n, r) - pairs(a, n, l-1);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}