#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

int s[100500];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int u, v, x;
        cin>>u>>v>>x;
        s[u]-=x;
        s[v]+=x;
    }
    vector<pair<pair<int, int>, int> > ans;
    vector<pair<int, int> > d;
    for(int i=1; i<=n; i++)
    d.pb({s[i], i});
    sort(d.begin(), d.end());
    int l=0;
    int r=n-1;
    while (r>l)
    {
        if ((d[l].fi==0) or (d[r].fi==0))
            break;
        if (d[l].fi+d[r].fi==0)
            ans.pb({{d[l].se, d[r].se}, d[r].fi}), l++, r--;
        else if (d[l].fi+d[r].fi>0)
        ans.pb({{d[l].se, d[r].se}, -d[l].fi}), d[r].fi+=d[l].fi, l++;
        else
        ans.pb({{d[l].se, d[r].se}, d[r].fi}), d[l].fi+=d[r].fi, r--;
    }
    cout<<ans.size()<<"\n";
    for (auto pa:ans)
        cout<<pa.fi.fi<<" "<<pa.fi.se<<" "<<pa.se<<"\n";
}