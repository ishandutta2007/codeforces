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

    int l[n+1], r[n+1];
    for(int i=1; i<=n; i++) cin>>l[i]>>r[i];

    for(int i=1; i<=n; i++)
    {
        cout<<l[i]<<" "<<r[i]<<" ";

        if(l[i]==r[i]) { cout<<l[i]<<endl; continue; }

        int mx = -1;
        for(int j=1; j<=n; j++)
        {
            if(l[j]==l[i] && r[j]<r[i]) mx = max(mx, r[j]);
        }

        if(mx==-1) cout<<l[i]<<endl;
        else cout<<mx+1<<endl;
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