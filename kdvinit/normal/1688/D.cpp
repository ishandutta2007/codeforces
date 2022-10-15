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
    for(int i=1; i<=n; i++) cin>>a[i];

    int pre[n+1]={0};
    for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];

    if(k>=n)
    {
        int ans = pre[n];

        ans += (k-1)*n;
        ans -= ((n*(n-1))/2);

        cout<<ans<<endl;
        return;
    }

    int ans = 0;
    int k2 = (k*(k-1))/2;

    for(int i=k; i<=n; i++)
    {
        int tmp = pre[i]-pre[i-k]+k2;
        ans = max(ans, tmp);
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