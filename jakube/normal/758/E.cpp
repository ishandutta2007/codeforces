#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int x, y;
    long long w, p;
};

struct SmallEdge {
    int to;
    int index;
};

vector<Edge> edges;
vector<vector<SmallEdge>> adj;
vector<long long> dpmin, dpmax, dpW;

void dfs(int v, int par) {
    for (auto next : adj[v]) {
        if (next.to == par) continue;
        dfs(next.to, v);
        Edge& e = edges[next.index];
        if (e.p < dpmin[next.to]) {
            cout << -1 << endl;
            exit(0);
        }
        dpmin[v] += dpmin[next.to] + e.w - min(e.p - dpmin[next.to], e.w - 1);
        dpmax[v] += e.w + min(e.p, dpmax[next.to]);
        dpW[v] += e.w + dpW[next.to];
    }
}

void dfs2(int v, int par, long long reduce) {
    vector<long long> reduce_by(adj[v].size(), 0);

    // reduce to max
    for (int i = 0; i < adj[v].size(); i++) {
        auto& next = adj[v][i];
        if (next.to == par) continue;
        auto &e = edges[next.index];
        long long max_to = min(dpmax[next.to], e.p);
        long long new_reduce = dpW[next.to] - max_to; 
        reduce_by[i] = new_reduce;
        reduce -= new_reduce;
    }

    // reduce even more if necessary
    for (int i = 0; i < adj[v].size(); i++) {
        auto& next = adj[v][i];
        if (next.to == par) continue;
        auto &e = edges[next.index];
        long long max_to = min(dpmax[next.to], e.p);
        long long new_reduce = min(reduce, max_to - dpmin[next.to]);
        reduce_by[i] += new_reduce;
        reduce -= new_reduce;
    }

    // reduce adj if necessary
    for (int i = 0; i < adj[v].size(); i++) {
        auto& next = adj[v][i];
        if (next.to == par) continue;
        auto& e = edges[next.index];
        if (reduce > 0) {
            long long new_reduce = min(reduce, min(e.w - 1, e.p - dpmin[next.to]));
            e.w -= new_reduce;
            e.p -= new_reduce;
            reduce -= new_reduce;
        }
    }

    // perform recursive reduce
    for (int i = 0; i < adj[v].size(); i++) {
        auto& next = adj[v][i];
        if (next.to == par) continue;
        dfs2(next.to, v, reduce_by[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    adj.resize(n);
    edges.resize(n-1);
    for (int i = 0; i < n - 1; i++) {
        Edge& e = edges[i];
        cin >> e.x >> e.y >> e.w >> e.p;
        e.x--;
        e.y--;
        adj[e.x].push_back({e.y, i});
        adj[e.y].push_back({e.x, i});
    }

    dpmin.assign(n, 0);
    dpmax.assign(n, 0);
    dpW.assign(n, 0);

    dfs(0, -1);
    dfs2(0, -1, dpW[0] - dpmax[0]);

    cout << n << '\n';
    for (auto e : edges) {
        cout << e.x + 1 << ' ' << e.y + 1 << ' ' << e.w << ' ' << e.p << '\n';
    }

    return 0;
}