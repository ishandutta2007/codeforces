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

    int par[n+1];
    for(int i=1; i<=n; i++) cin>>par[i];

    int per[n+1], tot[n+1];
    for(int i=1; i<=n; i++) { cin>>per[i]; tot[per[i]]=i-1; }

    int w[n+1];
    for(int i=1; i<=n; i++)
    {
        w[i] = tot[i]-tot[par[i]];
        if(w[i]<0) { cout<<-1<<endl; return; }
    }

    for(int i=1; i<=n; i++) cout<<w[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}