#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

vector<int> graph[maxn];
char used[maxn];

bool dfs(int v, int p=-1) {
    used[v] = true;
    bool ans = false;
    for (auto u: graph[v]) {
        if (u == p) continue;
        if (used[u]) {
            ans = true;
        } else {
            ans |= dfs(u, v);
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && !dfs(i)) {
            ans++;
        }
    }
    cout << ans << '\n';
}