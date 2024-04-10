#include <bits/stdc++.h>

constexpr int N = 1 << 17;

int n, m;
int Dep[N], Fa[N];

std::vector<int> g[N];

int bfs(int s) {
    Fa[s] = -1, Dep[s] = 0;
    std::queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : g[u]) {
            if (v == Fa[u]) continue;
            Dep[v] = Dep[u] + 1, Fa[v] = u, que.push(v);
        }
        if (que.empty()) return u;
    }
}

int ans;

int dfs(int u) {
    std::vector<int> s;
    for (int v : g[u]) {
        if (v == Fa[u]) continue;
        Fa[v] = u;
        s.push_back(dfs(v));
    }
    if (s.size() > 3) return 0;
    if (s.size() == 0) return 1;
    sort(s.begin(), s.end());
    for (int x : s) {
        if (x == 0) return 0;
    }
    if (s.size() == 1) {
        if (s[0] == 1) {
            ans = u;
            return -2;
        }
        return 0;
    } else if (s.size() == 2) {
        if (abs(s[0]) == abs(s[1]) && (s[0] > 0 || s[1] > 0)) return s[0] < 0 || s[1] < 0 ? -abs(s[0]) - 1 : s[0] + 1;
        return 0;
    } else {
        if (s[0] > 0 && s[0] == s[1] && s[2] == s[0] + 1) {
            ans = u;
            return -s[2] - 1;
        }
        return 0;
    }
}

int check(int r) {
    Fa[r] = -1;
    if (dfs(r) == -n) return ans;
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    m = (1 << n) - 2;
    for (int i = 0; i < m - 1; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s = bfs(0);
    int t = bfs(s);
    int diameter = Dep[t];
    for (int i = 0; i < diameter / 2; ++i) t = Fa[t];
    std::vector<int> ans;
    s = Fa[t];
    int x = check(t);
    if (x != -1) ans.push_back(x);
    x = check(s);
    if (x != -1) ans.push_back(x);
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    std::cout << ans.size() << "\n";
    for (int x : ans) std::cout << x + 1 << " \n"[x == ans.back()];
    return 0;
}