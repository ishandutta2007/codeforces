/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int nc2(int n)
{
    int ans = (n*(n-1))/2;
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans = 0;
    int cur = 0;

    for(int i=1; i<=n; i++)
    {
        cur++;
        if(a[i]<cur) cur=a[i];
        ans+=cur;
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