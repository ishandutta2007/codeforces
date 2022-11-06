#include <bits/stdc++.h>

using namespace std;

#define int long long

vector< vector<int> > graph;
vector<int> color;

int nodd, neven;
bool res_is_empty = false;

void dfs(int v, int c, int parent) {
    if (color[v] != -1) {
        if (color[v] != c) res_is_empty = true;
        return;
    }
    if (c == 0) neven++;
    else nodd++;
    color[v] = c;
    for (auto u: graph[v]) {
        if (u != parent) {
            dfs(u, !c, v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    if (m == 0) {
        cout << 3 << ' ' << n * (n - 1) * (n - 2) / 6 << '\n';
        return 0;
    }

    graph.assign(n, vector<int>());
    bool res_is_two = true;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (graph[a].size() > 1 || graph[b].size() > 1) {
            res_is_two = false;
        }
    }

    if (res_is_two) {
        cout << 2 << ' ' << m * (n - 2) << '\n';
        return 0;
    }

    color.assign(n, -1);
    int result = 0;
    for (int v = 0; v < n; v++) {
        if (color[v] == -1) {
            nodd = neven = 0;
            dfs(v, 0, -1);
            result += nodd * (nodd - 1) / 2 + neven * (neven - 1) / 2;
        }
    }

    if (res_is_empty) {
        cout << 0 << ' ' << 1 << '\n';
    } else {
        cout << 1 << ' ' << result << '\n';
    }


}