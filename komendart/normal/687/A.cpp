#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

vector<int> graph[maxn];
int color[maxn];
char used[maxn];
bool fail = false;

void dfs(int v, int c) {
    if (used[v]) {
        if (color[v] != c) fail = true;
        return;
    }
    used[v] = true;
    color[v] = c;
    for (auto u: graph[v]) {
        dfs(u, 3 - c);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i, 1);
    }

    if (fail) {
        cout << -1 << '\n';
        return 0;
    }
    cout << count(color, color + n, 1) << '\n';
    for (int i = 0; i < n; i++) {
        if (color[i] == 1) cout << i + 1 << ' ';
    }
    cout << '\n';
    cout << count(color, color + n, 2) << '\n';
    for (int i = 0; i < n; i++) {
        if (color[i] == 2) cout << i + 1 << ' ';
    }
}