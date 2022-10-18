#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> val;
vector<long long> res;

vector<bool> blocked;
vector<int> sz;
vector<int> cnt;
array<int, 21> good;

int dfs_size(int v, int p) {
    sz[v] = 1;
    for (int u : adj[v]) {
        if (!blocked[u] && u != p)
            sz[v] += dfs_size(u, v);
    }
    return sz[v];
}

int center(int v) {
    int total = dfs_size(v, v);
    bool found = false;
    int p = v;
    while (!found) {
        bool isCentroid = true;
        for (int u : adj[v]) {
            if (!blocked[u] && u != p && sz[u] * 2 > total) {
                p = v;
                v = u;
                isCentroid = false;
                break;
            }
        }
        if (isCentroid)
            found = true;
    }
    return v;
}

void addMasks(int v, int p, int mask, int add) {
    mask ^= val[v];
    cnt[mask] += add;
    for (int u : adj[v]) {
        if (!blocked[u] && u != p)
            addMasks(u, v, mask, add);
    }
}

long long solvePaths(int v, int p, int mask) {
    mask ^= val[v];
    long long total = 0;
    for (int g : good)
        total += cnt[g ^ mask];
    
    for (int u : adj[v]) {
        if (!blocked[u] && u != p) {
            total += solvePaths(u, v, mask);
        }
    }
    res[v] += total;
    return total;
}

void solve(int root) {
    root = center(root);
    for (int u : adj[root]) {
        if (!blocked[u])
            addMasks(u, root, 0, 1);
    }

    good[0] = val[root];
    for (int i = 0; i < 20; i++)
        good[i+1] = val[root] ^ (1 << i);

    // compute all paths going through root
    long long total = 0;
    cnt[0]++;
    for (int u : adj[root]) {
        if (!blocked[u]) {
            addMasks(u, root, 0, -1);
            total += solvePaths(u, root, 0);
            addMasks(u, root, 0, 1);
        }
    }
    cnt[0]--;
    // count all single paths again
    for (int g : good)
        total += cnt[g];
    // now divide to get every path once
    res[root] += total / 2;
    res[root]++; // only this node is also a palind

    // undo things
    for (int u : adj[root]) {
        if (!blocked[u])
            addMasks(u, root, 0, -1);
    }

    // block and recurse
    blocked[root] = true;
    for (int u : adj[root]) {
        if (!blocked[u])
            solve(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s;
    cin >> s;
    val.resize(n);
    for (int i = 0; i < n; i++) {
        val[i] = 1 << (s[i] - 'a');
    }
    
    res.assign(n, 0);
    sz.assign(n, 0);
    blocked.assign(n, false);
    cnt.assign(1 << 20, 0);
    solve(0);
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}