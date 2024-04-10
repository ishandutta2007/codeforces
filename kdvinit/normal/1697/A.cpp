/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        if(x>m)
        {
            ans+=(x-m);
            m=0;
        }
        else m-=x;
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