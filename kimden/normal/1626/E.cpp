#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct DSU {
    vector<int> v;
    vector<int> root;
    DSU(int n): v(n, -1), root(n) {
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (v[x] < 0) {
            return x;
        }
        return v[x] = find(v[x]);
    }

    int unite(int x, int y) {
        int new_root = y;
        x = find(x);
        y = find(y);
        if (x == y) {
            exit(1);
            return 0;
        }
        if (v[x] > v[y])
            swap(x, y);
        v[x] += v[y];
        v[y] = x;
        root[x] = new_root;
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        vector<set<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].insert(v);
            g[v].insert(u);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (c[i] == 0 && g[i].size() == 1) {
                q.push(i);
            }
        }
        DSU dsu(n);
        while (!q.empty()) {
            int z = q.front();
            q.pop();
            c[z] = -1;
            int nei = *g[z].begin();
            g[nei].erase(z);
            g[z].clear();
            dsu.unite(z, nei);
            if (c[nei] == 0 && g[nei].size() == 1) {
                q.push(nei);
            }
        }
        vector<int> leaves;
        bool all_yes = false;
        for (int i = 0; i < n; ++i) {
            if (c[i] == 1) {
                if (g[i].size() == 1) {
                    leaves.push_back(i);
                } else {
                    all_yes = true;
                    break;
                }
            }
        }
        if (!all_yes) {
            for (int x: leaves) {
                int nei = *g[x].begin();
                if (g[nei].size() >= 3) {
                    all_yes = true;
                    break;
                } else {
                    if (c[nei] != 1) {
                        c[nei] = 2;
                    }
                }
            }
        }
        if (all_yes) {
            for (int i = 0; i < n; ++i) {
                c[i] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int z = dsu.root[dsu.find(i)];
            if (i) {
                cout << " ";
            }
            if (c[z] >= 1) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
    }
}