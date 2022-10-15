/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, h, m;
    cin>>n>>h>>m;
    m+=(h*60);

    int tot = 24*60;
    int ans=tot;

    for(int i=1; i<=n; i++)
    {
        int h2, m2;
        cin>>h2>>m2;
        m2+=(h2*60);
        int cur = m2-m;
        if(cur<0) cur+=tot;
        ans = min(ans, cur);
    }

    cout<<(ans/60)<<" "<<(ans%60)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}