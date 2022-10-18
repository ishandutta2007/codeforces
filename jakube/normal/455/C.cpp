#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

class UnionFind {
public:
    vector<int> parent, rank;
    vector<int> center, diameter;

    UnionFind(int n) {
        rank.assign(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        diameter.resize(n);
    }

    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    void Union(int i, int j) {
        int x = find(i);
        int y = find(j);
        if (x != y) {
            if (rank[x] > rank[y]) {
                parent[y] = x;
            } else {
                parent[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

int max_diameter;

int find_diameter(int v, int par) {
    int long1 = 0, long2 = 0;
    for (int next : adj[v]) {
        if (next == par) continue;
        int tmp = find_diameter(next, v) + 1;
        if (tmp > long1) {
            long2 = long1;
            long1 = tmp;
        } else if (tmp > long2) {
            long2 = tmp;
        }
    }

    if (long1 + long2 > max_diameter) {
        max_diameter = long1 + long2;
    }

    return long1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, q;
    cin >> n >> m >> q;
    
    UnionFind uf(n);
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        uf.Union(u, v);
    }

    // compute diameters and centers
    for (int i = 0; i < n; i++) {
        if (uf.find(i) == i) {
            max_diameter = -1;
            find_diameter(i, -1);
            uf.diameter[i] = max_diameter;
        }
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            x--;
            x = uf.find(x);
            cout << uf.diameter[x] << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            x = uf.find(x);
            y = uf.find(y);
            if (x != y) {
                int from_center_x = (uf.diameter[x] + 1) / 2;
                int from_center_y = (uf.diameter[y] + 1) / 2;
                if (uf.diameter[x] > uf.diameter[y]) {
                    uf.parent[y] = x;
                    uf.diameter[x] = from_center_x + max(uf.diameter[x] / 2, from_center_y + 1);
                } else {
                    uf.parent[x] = y;
                    uf.diameter[y] = from_center_y + max(uf.diameter[y] / 2, from_center_x + 1);
                }
            }
        }
    }

    return 0;
}