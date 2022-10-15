/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int a[4];
    for(int i=1; i<=3; i++) cin>>a[i];

    for(int i=1; i<=3; i++)
    {
        int mx = -1;
        for(int j=1; j<=3; j++)
        {
            if(i==j) continue;
            mx = max(mx, a[j]);
        }
        mx++;
        int ans = mx-a[i];
        if(ans<0) ans=0;
        cout<<ans<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}