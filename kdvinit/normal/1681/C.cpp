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

    int a[n+1], sa[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; sa[i]=a[i]; }
    int b[n+1], sb[n+1];
    for(int i=1; i<=n; i++) { cin>>b[i]; sb[i]=b[i]; }

    sort(sa+1, sa+n+1);
    sort(sb+1, sb+n+1);

    map<array<int, 3>, int> ind;
    map<array<int, 2>, int> cnt;

    for(int i=1; i<=n; i++)
    {
        int cc = ++cnt[{sa[i], sb[i]}];
        ind[{sa[i], sb[i], cc}]=i;
    }

    cnt.clear();

    int perm[n+1];
    int pos[n+1];

    for(int i=1; i<=n; i++)
    {
        int cc = ++cnt[{a[i], b[i]}];
        int j = ind[{a[i], b[i], cc}];
        if(j==0) { cout<<-1<<endl; return; }
        perm[i]=j;
        pos[j]=i;
    }

    vector<array<int, 2>> swps;
    for(int i=1; i<=n; i++)
    {
        if(perm[i]==i) continue;
        int j=pos[i];
        swps.push_back({i, j});
        swap(perm[i], perm[j]);
        pos[i]=i;
        pos[perm[j]]=j;
    }

    cout<<swps.size()<<endl;
    for(auto cur: swps) cout<<cur[0]<<" "<<cur[1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}