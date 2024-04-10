#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> p = a;
    for (int i = 1; i < n; i++) p[i] += p[i - 1];
    set<pair<ll, ll>, greater<pair<ll, ll> > > q;
    set<pair<ll, ll> > l;
    l.insert({n, 0});
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
            q.insert({a[i], i});
        l.insert({i, a[i]});
    }
    vector<pair<ll, ll> > upd;
    upd.push_back({1e9 + 7, 1});
    while (q.size())
    {
        //cout << "! " << q.size() << endl;

        pair<ll, ll> s = *q.begin();
        ll id = s.second;
        auto it = l.find({s.second, s.first});
        it++;
        pair<ll, ll> x = *it;
        pair<ll, ll> t = {x.second, x.first};

        //cout << s.first << " " << s.second << endl;

        it++;
        //if (it == l.end())
        //    cout << "wrong here" << endl;
        pair<ll, ll> y = *it;

        q.erase(s);
        q.erase(t);
        l.erase({s.second, s.first});
        l.erase(x);

        if (y.first == n)
        {
            ll len = n - s.second;
            l.insert({s.second, 222});
            upd.push_back({s.first, len});
            continue;
        }
        ll len = y.first - s.second;
        ll tot = p[y.first - 1] - (s.second ? p[s.second - 1] : 0);
        upd.push_back({s.first, len});

        //cout << x.first << " " << y.first << endl;
        //cout << tot << endl;

        ll val = (tot + len - 1) / len;

        q.insert({val, s.second});
        l.insert({s.second, val});
    }
    //for (auto e : upd)
    //{
    //    cout << e.first << " " << e.second << "\n";
    //}
    vector<ll> asks(m);
    for (int i = 0; i < m; i++) cin >> asks[i];

    vector<ll> ans(m);
    for (ll i = m - 1, j = 0, cur = 1; i >= 0; i--)
    {
        //cout << asks[i] << " " << upd[j].first << endl;
        while (j < upd.size() && asks[i] < upd[j].first)
        {
            cur = max(cur, upd[j].second);
            j++;
        }
        ans[i] = cur;
    }
    for (int i = 0; i < m; i++) cout << ans[i] - 1 << " ";
}