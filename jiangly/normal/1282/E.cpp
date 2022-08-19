#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a(n - 2);
    map<pair<int, int>, int> id;
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 2; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        --z;
        a[i] = {x, y, z};
        if (id.find(minmax(x, y)) != id.end()) {
            int j = id[minmax(x, y)];
            id.erase(minmax(x, y));
            e[i].push_back(j);
            e[j].push_back(i);
        } else {
            id[minmax(x, y)] = i;
        }
        if (id.find(minmax(z, y)) != id.end()) {
            int j = id[minmax(z, y)];
            id.erase(minmax(z, y));
            e[i].push_back(j);
            e[j].push_back(i);
        } else {
            id[minmax(z, y)] = i;
        }
        if (id.find(minmax(x, z)) != id.end()) {
            int j = id[minmax(x, z)];
            id.erase(minmax(x, z));
            e[i].push_back(j);
            e[j].push_back(i);
        } else {
            id[minmax(x, z)] = i;
        }
    }
    vector<vector<int>> f(n);
    for (auto i : id) {
        int x, y;
        tie(x, y) = i.first;
        f[x].push_back(y);
        f[y].push_back(x);
    }
    int x = 0, y = f[x][0];
    vector<int> cyc{x};
    for (; y != 0; tie(x, y) = make_pair(y, f[y][0] ^ f[y][1] ^ x))
        cyc.push_back(y);
    for (int i : cyc)
        cout << i + 1 << " \n"[i == cyc.back()];
    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : e[u])
            if (v != p)
                dfs(v, u);
        cout << u + 1 << " \n"[u == 0];
    };
    dfs(0, -1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}