/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    array<int, 2> a[n+1];
    int ans=0;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i][0]>>a[i][1];
        ans+=a[i][1];
    }

    sort(a+1, a+n+1);

    int mx = a[1][0]+a[1][1];
    for(int i=2; i<=n; i++)
    {
        if(a[i][0]>mx) ans+=(a[i][0]-mx);
        mx = max(mx, a[i][0]+a[i][1]);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}