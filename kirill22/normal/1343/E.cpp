#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> g;

vector<int> solve(int v) {
    deque<int> a;
    int n = g.size();
    vector<int> d(n, 1e18);
    d[v] = 0;
    a.push_front(v);
    while (a.size() > 0) {
        auto p = a.front();
        a.pop_front();
        for (auto el : g[p]) {
            if (d[el] > d[p] + 1) {
                d[el] = d[p] + 1;
                a.push_back(el);
            }
        }
    }
    return d;
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--;
    b--;
    c--;
    g.resize(n);
    vector<int> p(m);
    for (int i = 0; i < m; i++) cin >> p[i];
    sort(p.begin(), p.end());
    vector<int> pref(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i - 1] + p[i - 1];
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> _a = solve(a);
    vector<int> _b = solve(b);
    vector<int> _c = solve(c);
    int ans = 2 * pref[m];
    for (int i = 0; i < n; i++) {
        int x = _a[i] + _b[i] + _c[i];
        if (x > m) continue;
        int y = _b[i];
        //cout << x << " " << y << " " << pref[x] + pref[y] << endl;
        ans = min(ans, pref[x] + pref[y]);
    }
    cout << ans << endl;
    g.clear();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}