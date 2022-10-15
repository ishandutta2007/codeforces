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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    sort(a+1, a+n+1);

    int mx=0;
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        int j=i;
        while(j<=n && a[i]==a[j])
        {
            j++;
            cnt++;
        }
        i=j-1;
        mx = max(mx, cnt);
    }

    int ans;
    if(2*mx<=n) ans=n%2;
    else ans = 2*(mx) - n;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}