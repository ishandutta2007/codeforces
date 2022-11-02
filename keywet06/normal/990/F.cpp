#include <bits/stdc++.h>

using namespace std;

typedef std::pair<int, int> pr;

const int N = 200200;

bool vis[N];

int cap[N];

int used[2 * N];

std::vector<pr> edges[N];

int dfs(int on) {
    vis[on] = true;
    int ans = cap[on];
    for (auto e : edges[on]) {
        if (vis[e.first]) continue;
        int need = dfs(e.first);
        used[e.second] -= need;
        ans += need;
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> cap[i];
        sum += cap[i];
    }
    if (sum != 0) {
        std::cout << "Impossible\n";
        return 0;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].emplace_back(v, 2 * i);
        edges[v].emplace_back(u, 2 * i + 1);
    }
    bool valid = true;
    for (int i = 0; i < n; ++i) {
        valid = valid && (vis[i] || dfs(i) == 0);
    }
    if (valid) {
        cout << "Possible\n";
        for (int i = 0; i < m; ++i) {
            cout << -(used[2 * i] - used[2 * i + 1]) << endl;
        }
    } else {
        cout << "Impossible\n";
    }
    return 0;
}