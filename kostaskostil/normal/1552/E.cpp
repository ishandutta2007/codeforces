#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

vector<vector<int> > v;
vector<pair<int, pair<int, int> > > s;
int col[100500];

int cnt[100500];
int used[105];
int n, k;
void try_()
{
    for (int i=1; i<=n*k; i++)
        cnt[i] = 0;
    for (int i=0; i<n; i++)
        used[i] = 0;
    set<int> bad;
    vector<pair<int, int> > ch;
    for (auto pa : s)
    {
        int l = pa.se.fi;
        int r = pa.se.se;
        int c = col[l];
        if (used[c])
            continue;
        auto it = bad.lower_bound(l);
        if ((it!=bad.end()) and (*it <= r))
            continue;
        used[c] = 1;
        ch.pb({l, r});
        for (int i=l; i<=r; i++)
        {
            cnt[i]++;
            if (cnt[i] == (n+k-2)/(k-1))
                bad.insert(i);
        }
    }
//    cout<<ch.size()<<endl;
    if (ch.size()==n)
    {
        sort(ch.begin(), ch.end(), [&](auto l, auto r){ return col[l.fi] < col[r.fi]; });
        for (auto pa : ch)
            cout<<pa.fi<<" "<<pa.se<<"\n";
        exit(0);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int _;
//    cin>>_;
//    while (_--)
//    {
        cin>>n>>k;
        v.resize(n);
        for (int i=1; i<=n*k; i++)
        {
            int q;
            cin>>q;
            col[i] = q-1;
            v[q-1].pb(i);
        }
        for (int i=0; i<n; i++)
            for (int j=0; j+1<k; j++)
        {
            s.pb({v[i][j+1] - v[i][j] + 1, {v[i][j], v[i][j+1]} });
        }
        int z = 0;
        while (true)
        {
//            vector<int>
            z++;
            if (z==1)
                sort(s.begin(), s.end());
            else
                break;//random_shuffle(s.begin(), s.end());
            try_();
        }
        vector<pair<int, int> > ans(n, {-1, -1});
        int r = n;
        while (r > 0)
        {
        map<int, int> mp;
        for (int i=1; i<=n*k; i++)
        {
            if (ans[col[i]].fi != -1)
                continue;
            if (mp.count(col[i]))
            {
//                cout<<mp[col[i]]<<" "<<i<<endl;
                ans[col[i]] = {mp[col[i]], i};
                mp.clear();
                r--;
            }
            else
                mp[col[i]] = i;
        }
        }
        for (auto pa : ans)
            cout<<pa.fi<<" "<<pa.se<<"\n";
//    }
}