/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int k, n, m;
    cin>>k>>n>>m;

    int a[n+2], b[m+2];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++) cin>>b[i];
    a[n+1]=1e5; b[m+1]=1e5;

    int ai=1, bi=1;
    vector<int> ans;
    while(1)
    {
        if(a[ai]==0) { ans.push_back(0); k++; ai++; continue; }
        if(b[bi]==0) { ans.push_back(0); k++; bi++; continue; }
        if(a[ai]<=k) { ans.push_back(a[ai]); ai++; continue; }
        if(b[bi]<=k) { ans.push_back(b[bi]); bi++; continue; }
        break;
    }
    int y = ans.size();
    if(y!=(n+m)) { cout<<-1<<endl; return; }
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}