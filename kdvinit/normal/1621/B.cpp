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

    int l[n+1], r[n+1], c[n+1];
    for(int i=1; i<=n; i++) cin>>l[i]>>r[i]>>c[i];

    int ml=l[1], mr=r[1], cl=c[1], cr=c[1];
    int pl=l[1], pr=r[1], pa=c[1];

    cout<<c[1]<<endl;
    for(int i=2; i<=n; i++)
    {
        if(l[i]<ml) { cl=c[i]; ml=l[i]; }
        else if(l[i]==ml) cl=min(cl, c[i]);

        if(r[i]>mr) { cr=c[i]; mr=r[i]; }
        else if(r[i]==mr) cr=min(cr, c[i]);

        int ans = cl+cr;
        if(l[i]==ml && r[i]==mr) ans = min(ans, c[i]);

        if(ml==pl && mr==pr) ans = min(ans, pa);
        cout<<ans<<endl;

        pl=ml; pr=mr; pa=ans;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}