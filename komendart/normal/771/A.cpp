#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 150 * 1000 + 10;

vector<int> graph[maxn];
char used[maxn];

void dfs(int v, int &vertex, int &edges) {
    used[v] = true;
    ++vertex;
    edges += graph[v].size();
    for (auto u: graph[v]) {
        if (!used[u]) {
            dfs(u, vertex, edges);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int vertex = 0;
            int edges = 0;
            dfs(i, vertex, edges);
            if (vertex * (vertex - 1) != edges) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}