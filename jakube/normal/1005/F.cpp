#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, idx;
};

struct Rotater {
    vector<int> v;
    int idx = 0;
    int n;

    Rotater(vector<int> v) : v(v), n(v.size()) { }

    bool rotate() {
        idx++;
        if (idx == n)
            idx = 0;
        return !idx;
    }

    int operator()() const {
        return v[idx];
    }
};

struct MSTS {
    vector<Rotater>  rotater;
    MSTS(vector<vector<int>> w) {
        for (auto x : w)
            rotater.emplace_back(x);
    }
    
    int cnt() {
        long long res = 1;
        for (auto r : rotater) {
            res *= r.n;
            res = min(res, (long long)std::numeric_limits<int>::max());
        }
        return res;
    }

    vector<int> next() {
        vector<int> out;
        for (auto r : rotater) {
            out.push_back(r());
        }
        for (int i = (int)rotater.size() - 1; i >= 0; i--) {
            if (!rotater[i].rotate())
                break;
        }
        return out;
    }
};

bool next_combination(vector<int> &v, int k)
{
    int n = v.size();
    for (int i = 1; i <= k; ++i) {
        if (v[k-i] < n-i) {
            ++v[k-i];
            for (int j = k-i+1; j < k; ++j) {
                v[j] = v[j-1] + 1;
            }
            return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<Edge>> adj;
    adj.resize(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges[i] = {u, v};
    }
    
    std::vector<bool> found(n, false);
    std::queue<std::pair<int, int>> q;

    q.push({0, 0});
    found[0] = true;

    vector<int> dists(n);
    while (!q.empty()) {
        auto p = q.front();
        int cur = p.first;
        int dist = p.second;
        q.pop();
        dists[cur] = dist;
        for (auto [next, idx] : adj[cur]) {
            if (!found[next]) {
                q.push({next, dist + 1});
                found[next] = true;
            }
        }
    }

    vector<vector<int>> w(n - 1);
    for (int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        int a = dists[u];
        int b = dists[v];
        if (a < b)
            w[v-1].push_back(i);
        if (b < a)
            w[u-1].push_back(i);
    }

    MSTS msts(w);
    k = min(k, msts.cnt());
    vector<bool> used(m, false);
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        auto r = msts.next();
        for (int idx : r)
            used[idx] = true;
        for (bool b : used)
            cout << (b ? 1 : 0);
        cout << '\n';
        for (int idx : r)
            used[idx] = false;
    }
}