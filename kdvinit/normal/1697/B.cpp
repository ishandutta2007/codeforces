/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, q;
    cin>>n>>q;

    int a[n+1]={0};
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    for(int i=1; i<=n; i++) a[i]+=a[i-1];

    while(q--)
    {
        int x, y;
        cin>>x>>y;
        int ans=a[n-x+y]-a[n-x];
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}