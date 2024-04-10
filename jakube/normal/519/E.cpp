#include <bits/stdc++.h>
using namespace std;

vector<int> mylog;
vector<vector<int>> adj;
vector<int> height;
vector<vector<int>> parent;
vector<int> size;
int maxlog = 20;

void dfs(int u, int p, int h) {
    height[u] = h;

    parent[u][0] = p;
    for (int i = 1; i < maxlog; i++) {
        if (parent[u][i-1] >= 0) parent[u][i] = parent[parent[u][i-1]][i-1];
    }

    size[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, h + 1);
        size[u] += size[v];
    }
}

int lca(int u, int v) {
    if (height[u] < height[v])
        swap(u, v);

    for (int i = maxlog - 1; i >= 0; i--) {
        if (parent[u][i] >= 0 && height[parent[u][i]] >= height[v])
            u = parent[u][i];
    }

    if (u == v)
        return u;

    for (int i = maxlog - 1; i >= 0; i--) {
        if (parent[u][i] >= 0 && parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mylog.resize(1e5 + 1);
    mylog[0] = 0;
    for (int i = 1; i < mylog.size(); i++)
        mylog[i] = mylog[i/2] + 1;

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    height.resize(n);
    parent.assign(n, vector<int>(maxlog, -1));
    size.resize(n);
    dfs(0, -1, 0);
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int a = lca(x, y);

        int dist = height[x] + height[y] - 2 * height[a];
        if (dist % 2) {
            cout << 0 << '\n';
            continue;
        }

        if (x == y) {
            cout << n << '\n';
            continue;
        }

        auto go_up = [](int u, int cnt) {
            for (int i = maxlog - 1; i >= 0; i--) {
                if (cnt & (1 << i))
                    u = parent[u][i];
            }
            return u;
        };

        if (height[x] == height[y]) {
            int below_center1 = go_up(x, dist / 2 - 1);
            int below_center2 = go_up(y, dist / 2 - 1);
            cout << n - size[below_center1] - size[below_center2] << '\n';
            continue;
        }

        if (height[x] < height[y])
            swap(x, y);

        int center = go_up(x, dist / 2);
        int below_center = go_up(x, dist / 2 - 1);
        cout << size[center] - size[below_center] << '\n';
        continue;
    }
}