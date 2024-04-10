/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, c;
    cin>>n>>c;

    int a[n+1], b[n];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<n; i++) cin>>b[i];

    int ans = 1e12;
    int sum = 0;
    int days = 0;

    for(int i=1; i<=n; i++)
    {
        if(sum>=c) break;
        int x = (c-sum+a[i]-1)/a[i];
        ans = min(ans, days+x);

        if(i==n) break;

        if(sum>b[i])
        {
            days++;
            sum-=b[i];
            continue;
        }

        x = (b[i]-sum+a[i]-1)/a[i];
        days+=x+1;
        sum+=(x*a[i]);
        sum-=b[i];
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