/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=(i-1);
    }
    sort(a+1, a+n+1);

    int nk=n-k;

    int ans=0;
    for(int i=1; i<=nk; i++)
    {
        ans+=a[i];
        ans-=(i-1);
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