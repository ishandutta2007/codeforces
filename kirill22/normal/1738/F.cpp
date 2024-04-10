#include "bits/stdc++.h"

using namespace std;

class dsu {
public:
    vector<int> p;
    int n;
    dsu(int n) : n(n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    void clear() {
        iota(p.begin(), p.end(), 0);
    }
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i].first;
        d[i].second = i;
    }
    dsu g(n);
    sort(d.rbegin(), d.rend());
    vector<int> used(n);
    for (auto [x, v] : d) {
        if (used[v]) {
            continue;
        }
        used[v] = 1;
        while (x--) {
            cout << "? " << v + 1 << endl;
            int u;
            cin >> u;
            u--;
            if (!used[u]) {
                used[u] = 1;
                g.unite(u, v);
            } else {
                g.unite(u, v);
                break;
            }
        }
    }
    vector<int> ans(n);
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        G[g.get(i)].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        for (auto v : G[i]) {
            ans[v] = i + 1;
        }
    }
    cout << "! ";
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}