#include <bits/stdc++.h>

using namespace std;

int n, m;
vector< set<int> > graph;
vector<char> need;

int far = 1e9;
int maxdist = 0;

void dfs(int v, int parent=-1, int depth=0) {
    if (depth == maxdist) far = min(far, v);
    else if (depth > maxdist) {
        far = v;
        maxdist = depth;
    }
    for (auto u: graph[v]) {
        if (u != parent) dfs(u, v, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    graph.assign(n, set<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    need.assign(n, false);
    for (int i = 0; i < m; i++) {
        int t; cin >> t; t--;
        need[t] = true;
    }

    vector<int> q;
    for (int i = 0; i < n; i++) {
        if (!need[i] && graph[i].size() == 1) {
            q.push_back(i);
        }
    }

    int rest = n - 1;
    while (!q.empty()) {
        int v = q.back(); q.pop_back();
        for (auto u: graph[v]) {
            graph[u].erase(v);
            if (!need[u] && graph[u].size() == 1) {
                q.push_back(u);
            }
        }
        graph[v].clear();
        rest--;
    }

    for (int i = 0; i < n; i++) {
        if (need[i]) {
            dfs(i);
            int far1 = far;
            dfs(far);
            cout << min(far, far1) + 1 << '\n';
            cout << 2 * rest - maxdist << '\n';
            return 0;
        }
    }
}