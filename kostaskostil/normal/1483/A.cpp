#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

void solve(int _)
{
    int n, m;
    cin>>n>>m;
    vector<pair<pair<int, int>, vector<int> > > data(m);
    for (int i=0; i<m; i++)
    {
        int k;
        cin>>k;
        vector<int> v(k);
        for (int& j : v)
            cin>>j;
        data[i] = { {k, i}, v };
    }
    sort(data.begin(), data.end());
    vector<int> ans(m);
    vector<int> cnt(n+1);
    bool ok = true;
    for (int i=0; i<m; i++)
    {
        int ind = data[i].fi.se;
        int mn = 1e9;
        int ix = -1;
        for (int j : data[i].se)
            if (mn > cnt[j])
                ix = j, mn = cnt[j];
        ans[ind]=ix;
        cnt[ix]++;
        if (cnt[ix] > ((m+1) / 2))
            ok=false;

    }

    if (ok)
    {
        cout<<"YES\n";
        for (int i: ans)
            cout<<i<<" ";
        cout<<"\n";
    }
    else
        cout<<"NO\n";


}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _ = 1; _ <= ___; _++)
    {
        solve(_);
    }
}