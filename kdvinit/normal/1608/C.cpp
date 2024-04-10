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

    pair<int, int> a[n+1], b[n+1];
    for(int i=1; i<=n; i++) { int x; cin>>x; a[i]={x, i}; }
    for(int i=1; i<=n; i++) { int x; cin>>x; b[i]={x, i}; }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    map<int, int> ap, pa, bp, pb;
    for(int i=1; i<=n; i++) { int j = a[i].second; ap[i]=j; pa[j]=i; }
    for(int i=1; i<=n; i++) { int j = b[i].second; bp[i]=j; pb[j]=i; }

    int dpa[n+1], dpb[n+1];
    dpa[n] = pb[ap[n]]; dpb[n] = pa[bp[n]];

    for(int i=n-1; i>=1; i--)
    {
        dpa[i] = min(dpa[i+1], pb[ap[i]]);
        dpb[i] = min(dpb[i+1], pa[bp[i]]);
    }

    int mn=n;
    while(1)
    {
        int j = dpa[mn];
        int i = dpb[j];
        if(i==mn) break;
        mn--;
    }

    int ans[n+1]={0};
    for(int i=mn; i<=n; i++) ans[ap[i]]=1;

    for(int i=1; i<=n; i++) cout<<ans[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}