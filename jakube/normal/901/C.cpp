#include <bits/stdc++.h>
using namespace std;

struct S
{
    int to;
    int idx;
    int from;
};

vector<vector<S>> adj;
vector<int> pre, last_edge;
vector<bool> visited;
vector<vector<int>> cycles;
vector<bool> inCycle;

void dfs(int v, int p = -1, int last = -1) {
    pre[v] = p;
    last_edge[v] = last;
    visited[v] = true;
    for (auto u : adj[v]) {
        if (u.to == p) {
            continue;
        }
        if (visited[u.to]) {
            if (!inCycle[u.idx]) {
                cycles.push_back({});
                int a = u.to;
                inCycle[u.idx] = true;
                cycles.back().push_back(u.idx);
                a = v;
                do {
                    inCycle[last_edge[a]] = true;
                    cycles.back().push_back(last_edge[a]);
                    a = pre[a];
                } while (a != u.to);
            }
        } else {
            dfs(u.to, v, u.idx);
        }
    }
}

vector<int> cycleIdx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;
    adj.resize(n);
    vector<S> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i, u});
        adj[v].push_back({u, i, v});
        edges.push_back({u, i, v});
    }
    pre.assign(n, -1);

    inCycle.assign(max(n, m), false);
    visited.assign(max(n, m), false);
    last_edge.assign(max(n, m), -1);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }

//     cycleIdx.assign(m, -1);
//     inCycle.assign(m, false);

//     int idx = 0;
//     for (auto& c : cycles) {
//         for (auto i : c) {
//             inCycle[i] = true;
//             cycleIdx[i] = idx;
//         }
//         idx++;
//     }

    vector<vector<int>> inCycles(n);
    vector<int> cycle_sizes;
    for (auto& c : cycles) {
        cycle_sizes.push_back(2 * c.size());
        for (auto idx : c) {
            auto& e = edges[idx];
            inCycles[e.to].push_back(cycle_sizes.size() - 1);
            inCycles[e.from].push_back(cycle_sizes.size() - 1);
        }
    }

    vector<int> upto(n);
    int conflicts = 0;
    int last = -1;
    for (int start = 0; start < n; start++) {
        if (conflicts) {
            upto[start] = upto[start - 1];
        } else {
            for (last++; last < n; last++) {
                // add vertex
                for (auto ci : inCycles[last]) {
                    cycle_sizes[ci]--;
                    if (cycle_sizes[ci] == 0)
                       conflicts++;
                }
                if (conflicts) 
                    break;
            }
            upto[start] = min(last-1, n-1);
        }

        // remove edge
        for (auto ci : inCycles[start]) {
            if (cycle_sizes[ci] == 0)
               conflicts--;
            cycle_sizes[ci]++;
        }
    }

    for (auto& x : upto)
        x++;

    vector<long long> psum(upto.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < upto.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + upto[psum_idx];
    }

    auto gauss = [](long long x) {
        return x * (x + 1) / 2;
    };

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        auto idx = lower_bound(upto.begin(), upto.end(), b + 1) - upto.begin();
        if (idx < a) {
            cout << gauss(b - a + 1) << endl;
        } else {
            long long sum = psum[idx] - psum[a];
            int others = b - idx + 1;
            sum += gauss(others);
            sum -= gauss(idx - 1);
            sum += gauss(a - 1);
            cout << sum << endl;
        }
    }
}