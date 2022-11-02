#include <bits/stdc++.h>

using namespace std;

const int N = 500000;

int n, dfsNow;
int a[4 * N][2], ans[2 * N], dp[N][2], up[N];

vector<int> e[N];
vector<pair<int, int>> cnt[N];

void push(int p, int l, int r) {
    if (r - l == 1) {
        ans[2 * l - 1] = max(ans[2 * l - 1], a[p][0]);
        ans[2 * l] = max(ans[2 * l], a[p][1]);
        return;
    }
    int m = (l + r) / 2;
    for (int k = 0; k < 2; ++k) {
        a[2 * p][k] = max(a[2 * p][k], a[p][k]);
        a[2 * p + 1][k] = max(a[2 * p + 1][k], a[p][k]);
    }
    push(2 * p, l, m);
    push(2 * p + 1, m, r);
}

void modify(int p, int l, int r, int x, int y, int k, int v) {
    if (l >= y || r <= x) return;
    if (l >= x && r <= y) {
        a[p][k] = max(a[p][k], v);
        return;
    }
    int m = (l + r) / 2;
    modify(2 * p, l, m, x, y, k, v);
    modify(2 * p + 1, m, r, x, y, k, v);
}

void dfs1(int u, int p) {
    if (p != -1) e[u].erase(find(e[u].begin(), e[u].end(), p));
    for (int v : e[u]) {
        dfs1(v, u);
        int x = dp[v][0] + 1;
        if (x > dp[u][0]) swap(x, dp[u][0]);
        dp[u][1] = max(dp[u][1], x);
    }
}

vector<pair<int, int>> merge(const vector<pair<int, int>> &lhs, const

                             vector<pair<int, int>> &rhs) {
    vector<pair<int, int>> res;
    int i = 0, j = 0;
    while (i < lhs.size() || j < rhs.size()) {
        int x = 1E9, y = 0;
        if (i < lhs.size()) {
            x = min(x, lhs[i].first);
            y = max(y, lhs[i].second);
        }
        if (j < rhs.size()) {
            x = min(x, rhs[j].first);
            y = max(y, rhs[j].second);
        }
        res.emplace_back(x, y);
        if (i < lhs.size() && lhs[i].first == x) ++i;
        if (j < rhs.size() && rhs[j].first == x) ++j;
    }
    return res;
}

vector<pair<int, int>> mergeAll(const vector<int> &a, int l, int r) {
    if (r - l == 1) return cnt[a[l]];
    int m = (l + r) / 2;
    return merge(mergeAll(a, l, m), mergeAll(a, m, r));
}

void dfs2(int u, int p) {
    if (e[u].size() == 0) return;
    vector<int> a;
    for (int v : e[u]) {
        up[v] =
            1 + max(up[u], (dp[v][0] + 1 == dp[u][0] ? dp[u][1] : dp[u][0]));
        a.push_back(dp[v][0] + 1);
        dfs2(v, u);
    }
    if (p != -1) a.push_back(up[u]);
    sort(a.begin(), a.end());
    int lst = 0;
    for (int i = 0; i < a.size();) {
        modify(1, 1, n, max(1, lst), a[i], 1, a.size() - i);
        modify(1, 1, n, lst + 1, a[i] + 1, 0, a.size() - i);
        if (lst != 0)
            modify(1, 1, n, cnt[u].back().first, cnt[u].back().first + 1, 1,
                   a.size() - i + 1);
        cnt[u].emplace_back(a[i], a.size() - i);
        lst = a[i];
        ++i;
        while (i < a.size() && a[i - 1] == a[i]) ++i;
    }
    auto ch = mergeAll(e[u], 0, e[u].size());
    int i = 0, j = 0;
    lst = 1;
    while (i < cnt[u].size() && j < ch.size()) {
        int x = min(cnt[u][i].first, ch[j].first);
        int y = cnt[u][i].second + ch[j].second - 2;
        modify(1, 1, n, lst, x + 1, 0, y);
        lst = x + 1;
        if (cnt[u][i].first == x) ++i;
        if (ch[j].first == x) ++j;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    fill(ans, ans + n, 1);
    for (int i = 0; i < n; ++i) ans[0] = max(ans[0], (int)e[i].size() + 1);
    dfs1(0, -1);
    dfs2(0, -1);
    push(1, 1, n);
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
    return 0;
}