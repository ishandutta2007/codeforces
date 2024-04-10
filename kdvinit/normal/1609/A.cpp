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

    int a[n+1], mul=1, ans=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        while(a[i]%2==0) { a[i]/=2; mul*=2; }
        ans+=a[i];
    }
    sort(a+1, a+n+1);
    ans -= a[n];
    ans += (mul*a[n]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}