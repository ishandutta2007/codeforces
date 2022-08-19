#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2E2, M = 4 * N * (N - 1);
string type, s;
int n, m, l;
vector<int> e[2 * N];
int dfn[2 * N], be[2 * N], low[2 * N], t[26], deg[2 * N], c[2];
vector<int> stk;
int dfs_now, cnt;
void init() {
    for (int i = 0; i < 2 * n; ++i)
        while ((int)e[i].size() > deg[i])
            e[i].pop_back();
    memset(dfn, -1, 2 * n * sizeof(int));
    memset(be, -1, 2 * n * sizeof(int));
    dfs_now = cnt = 0;
}
void tarjan(int u) {
    dfn[u] = low[u] = dfs_now++;
    stk.push_back(u);
    for (int v : e[u]) {
        if (dfn[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (be[v] == -1) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        int v;
        do {
            v = stk.back();
            stk.pop_back();
            be[v] = cnt;
        } while (v != u);
        ++cnt;
    }
}
bool check() {
    for (int i = 0; i < 2 * n; ++i)
        if (dfn[i] == -1)
            tarjan(i);
    for (int i = 0; i < n; ++i)
        if (be[2 * i] == be[2 * i + 1])
            return false;
    return true;
}
void solve(int len) {
    for (int i = len + 1; i < n; ++i) {
        int mn = l;
        init();
        for (int j = 0; j < i; ++j)
            e[2 * j + !t[s[j] - 'a']].push_back(2 * j + t[s[j] - 'a']);
        e[2 * i + 1].push_back(2 * i);
        if (check())
            mn = min(mn, c[0]);
        init();
        for (int j = 0; j < i; ++j)
            e[2 * j + !t[s[j] - 'a']].push_back(2 * j + t[s[j] - 'a']);
        e[2 * i].push_back(2 * i + 1);
        if (check())
            mn = min(mn, c[1]);
        s[i] = mn + 'a';
    }
    cout << s << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> type >> n >> m;
    l = (int)type.length();
    for (int i = 0; i < l; ++i)
        t[i] = type[i] == 'C';
    for (int x = 0; x < 2; ++x) {
        while (c[x] < l && t[c[x]] != x)
            ++c[x];
        if (c[x] == l)
            for (int i = 0; i < n; ++i)
                e[2 * i + x].push_back(2 * i + !x);
    }
    for (int i = 0; i < m; ++i) {
        int p1, p2;
        char ct1, ct2;
        cin >> p1 >> ct1 >> p2 >> ct2;
        int t1 = ct1 == 'C', t2 = ct2 == 'C';
        --p1;
        --p2;
        e[2 * p1 + t1].push_back(2 * p2 + t2);
        e[2 * p2 + !t2].push_back(2 * p1 + !t1);
    }
    for (int i = 0; i < 2 * n; ++i)
        deg[i] = (int)e[i].size();
    cin >> s;
    for (int len = n; len >= 0; --len) {
        if (len == n) {
            init();
            for (int i = 0; i < len; ++i)
                e[2 * i + !t[s[i] - 'a']].push_back(2 * i + t[s[i] - 'a']);
            if (check()) {
                cout << s << "\n";
                return 0;
            }
            continue;
        }
        int mn = l;
        int j = s[len] - 'a' + 1;
        while (j < l && t[j] == 1)
            ++j;
        if (j < l) {
            init();
            for (int i = 0; i < len; ++i)
                e[2 * i + !t[s[i] - 'a']].push_back(2 * i + t[s[i] - 'a']);
            e[2 * len + 1].push_back(2 * len);
            if (check())
                mn = min(mn, j);
        }
        j = s[len] - 'a' + 1;
        while (j < l && t[j] == 0)
            ++j;
        if (j < l) {
            init();
            for (int i = 0; i < len; ++i)
                e[2 * i + !t[s[i] - 'a']].push_back(2 * i + t[s[i] - 'a']);
            e[2 * len].push_back(2 * len + 1);
            if (check())
                mn = min(mn, j);
        }
        if (mn < l) {
            s[len] = 'a' + mn;
            solve(len);
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}