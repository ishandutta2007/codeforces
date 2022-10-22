#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector<vector<int>> g;

vector<int> d, d2;
vector<bool> used;

void get() {
    set<pair<int, int>> b;
    b.insert({0, 0});
    used[0] = true;
    while (b.size() > 0) {
        auto x = *b.begin();
        b.erase(b.begin());
        d[x.second] = x.first;
        for (auto el : g[x.second]) {
            if (!used[el]) {
                b.insert({x.first + 1, el});
                used[el] = true;
            }
        }
    }
}

void get2() {
    set<pair<int, int>> b;
    b.insert({0, n - 1});
    used[n - 1] = true;
    while (b.size() > 0) {
        auto x = *b.begin();
        b.erase(b.begin());
        d2[x.second] = x.first;
        for (auto el : g[x.second]) {
            if (!used[el]) {
                b.insert({x.first + 1, el});
                used[el] = true;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }
    g.resize(n);
    d.resize(n, -1);
    d2.resize(n, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    used.clear();
    used.resize(n, false);
    get();
    used.clear();
    used.resize(n, false);
    get2();
    vector<pair<int, int>> c;
    for (auto el : a) {
        c.push_back({d[el] - d2[el], el});
    }
    int ans = 0;
    sort(c.rbegin(), c.rend());
    int mx = d2[c[0].second];
    for (int i = 1; i < k; i++) {
        int Z = mx + 1 + d[c[i].second];
        mx = max(mx, d2[c[i].second]);
        ans = max(ans, min(Z, d[n - 1]));
        //cout << c[i].second << " " << mx << " " << Z << endl;
    }
    cout << ans;
}