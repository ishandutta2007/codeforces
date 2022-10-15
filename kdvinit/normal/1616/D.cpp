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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int x;
    cin>>x;

    int ans = n, lst=0;
    int sum=0;

    for(int i=1; i<=n; i++)
    {
        if(i==lst+1)
        {
            sum = a[i]-x;
            continue;
        }

        sum += (a[i]-x);
        if(sum<0) { sum=0; lst=i; ans--; }

        sum = min(sum, a[i]-x);
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