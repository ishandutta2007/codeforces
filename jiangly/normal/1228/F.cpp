#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
constexpr int MAX_N = 1 << 17;
int n, N;
vector<int> g[MAX_N];
int dep[MAX_N], parent[MAX_N];
int bfs(int s) {
    parent[s] = -1;
    dep[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : g[u]) {
            if (v == parent[u])
                continue;
            dep[v] = dep[u] + 1;
            parent[v] = u;
            que.push(v);
        }
        if (que.empty())
            return u;
    }
    assert(false);
    return -1;
}
int ans;
int dfs(int u) {
    vector<int> s;
    for (int v : g[u]) {
        if (v == parent[u])
            continue;
        parent[v] = u;
        s.push_back(dfs(v));
    }
    if (s.size() > 3)
        return 0;
    if (s.size() == 0)
        return 1;
    sort(s.begin(), s.end());
    for (int x : s)
        if (x == 0)
            return 0;
    if (s.size() == 1) {
        if (s[0] == 1) {
            ans = u;
            return -2;
        }
        return 0;
    } else if (s.size() == 2) {
        if (abs(s[0]) == abs(s[1]) && (s[0] > 0 || s[1] > 0))
            return s[0] < 0 || s[1] < 0 ? -abs(s[0]) - 1 : s[0] + 1;
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
    parent[r] = -1;
    if (dfs(r) == -n)
        return ans;
    return -1;
}
void solve(int case_id) {
    cin >> n;
    N = (1 << n) - 2;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s = bfs(0);
    int t = bfs(s);
    int diameter = dep[t];
    for (int i = 0; i < diameter / 2; ++i)
        t = parent[t];
    vector<int> ans;
    s = parent[t];
    int x = check(t);
    if (x != -1)
        ans.push_back(x);
    x = check(s);
    if (x != -1)
        ans.push_back(x);
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x + 1 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}