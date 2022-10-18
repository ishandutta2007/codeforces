#include <bits/stdc++.h>
using namespace std;

vector<int> mylog;
vector<vector<int>> adj;
vector<vector<int>> parent;
vector<vector<vector<int>>> path;
vector<int> height;
int maxlog;
vector<vector<int>> numbers;

vector<int> combine(vector<int> a, vector<int> b) {
    vector<int> result(20);
    merge(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    result.resize(min(10, (int)a.size() + (int)b.size()));
    return result;
}

void dfs(int u, int p, int h) {
    height[u] = h;
    parent[u][0] = p;
    path[u][0] = numbers[u];
    for (int i = 1; i < maxlog && parent[u][i-1] >= 0; i++) {
        parent[u][i] = parent[parent[u][i-1]][i-1];
        path[u][i] = combine(path[u][i-1], path[parent[u][i-1]][i-1]);
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, h + 1);
    }
}

vector<int> lca(int u, int v) {
    if (height[u] < height[v]) {
        swap(u, v);
    }

    vector<int> pa;
    for (int i = maxlog - 1; i >= 0; i--) {
        if (parent[u][i] != -1 && height[parent[u][i]] >= height[v]) {
            pa = combine(pa, path[u][i]);
            u = parent[u][i];
        }
    }

    if (u == v) {
        pa = combine(pa, numbers[u]);
        return pa;
    }

    for (int i = maxlog - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            pa = combine(pa, path[u][i]);
            pa = combine(pa, path[v][i]);
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    pa = combine(pa, path[u][1]);
    pa = combine(pa, path[v][0]);
    u = parent[u][0];
    return pa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    mylog.resize(n);
    mylog[0] = 0;
    for (int i = 1; i < n; i++)
        mylog[i] = mylog[i / 2] + 1;

    adj.resize(n);
    maxlog = mylog[n-1];
    parent.assign(n, vector<int>(maxlog + 1, -1));
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    height.resize(n);

    numbers.resize(n);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        numbers[x-1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        sort(numbers[i].begin(), numbers[i].end());
        if (numbers[i].size() > 10)
            numbers[i].resize(10);
    }

    path.assign(n, vector<vector<int>>(maxlog + 1));

    dfs(0, -1, 0);

    for (int i = 0; i < q; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        u--;
        v--;
        vector<int> pa = lca(u, v);
        a = min(a, (int)pa.size());
        cout << a;
        for (int j = 0; j < a; j++)
            cout << ' ' << pa[j] + 1;
        cout << '\n';
    }
}