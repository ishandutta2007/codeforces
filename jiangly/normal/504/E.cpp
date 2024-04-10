#include <bits/stdc++.h>
using namespace std;
int n, m, dfs_now;
vector<int> sz, top, in, parent, dep, sa, lc, lg, rk;
string s, str;
vector<vector<int>> e, st;
void dfsSize(int u) {
    if (parent[u] != -1) {
        swap(*find(e[u].begin(), e[u].end(), parent[u]), e[u].back());
        e[u].pop_back();
    }
    sz[u] = 1;
    for (int &v : e[u]) {
        parent[v] = u;
        dep[v] = dep[u] + 1;
        dfsSize(v);
        sz[u] += sz[v];
        if (sz[v] > sz[e[u][0]])
            swap(v, e[u][0]);
    }
}
void dfsHLD(int u) {
    in[u] = dfs_now++;
    str[in[u]] = str[2 * n - in[u] - 1] = s[u];
    for (int v : e[u]) {
        top[v] = v == e[u][0] ? top[u] : v;
        dfsHLD(v);
    }
}
void buildSA() {
    str += '$';
    int n = str.size();
    int k = 1;
    sa.resize(n);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int i, int j) {return str[i] < str[j];});
    rk.resize(n);
    rk[sa[0]] = 0;
    for (int i = 1; i < n; ++i)
        rk[sa[i]] = rk[sa[i - 1]] + (str[sa[i]] != str[sa[i - 1]]);
    vector<int> cnt, tmp;
    while (rk[sa.back()] != n - 1) {
        tmp.reserve(n);
        for (int i = n - k; i < n; ++i)
            tmp.push_back(i);
        for (int i : sa)
            if (i >= k)
                tmp.push_back(i - k);
        cnt.assign(n, 0);
        for (int i = 0; i < n; ++i)
            ++cnt[rk[i]];
        for (int i = 1; i < n; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n; i--; )
            sa[--cnt[rk[tmp[i]]]] = tmp[i];
        tmp = rk;
        rk[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i]] != tmp[sa[i - 1]] || tmp[sa[i] + k] != tmp[sa[i - 1] + k]);
        tmp.clear();
        k *= 2;
    }
    sa.erase(sa.begin());
    str.pop_back();
    rk.pop_back();
    for (int &i : rk)
        --i;
    --n;
    k = 0;
    lc.resize(n - 1);
    for (int i = 0; i < n; ++i) {
        if (rk[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rk[i] + 1];
        while (i + k < n && j + k < n && str[i + k] == str[j + k])
            ++k;
        lc[rk[i]] = k;
        if (k > 0)
            --k;
    }
}
void buildRMQ() {
    int n = lc.size();
    st.resize(n);
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
    for (int i = n; i--; ) {
        st[i].resize(lg[n - i] + 1);
        st[i][0] = lc[i];
        for (int j = 1; j <= lg[n - i]; ++j)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    
}
int rmq(int l, int r) {
    int k = lg[r - l];
    return min(st[l][k], st[r - (1 << k)][k]);
}
int lcp(int i, int j) {
    if (i == j)
        return n;
    if (rk[i] > rk[j])
        swap(i, j);
    return rmq(rk[i], rk[j]);
}
vector<pair<int, int>> getPath(int u, int v) {
    vector<pair<int, int>> l, r;
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            l.emplace_back(2 * n - 1 - in[u], in[u] + 1 - in[top[u]]);
            u = parent[top[u]];
        } else {
            r.emplace_back(in[top[v]], in[v] + 1 - in[top[v]]);
            v = parent[top[v]];
        }
    }
    if (dep[u] <= dep[v])
        l.emplace_back(in[u], in[v] - in[u] + 1);
    else
        l.emplace_back(2 * n - 1 - in[u], in[u] - in[v] + 1);
    reverse(r.begin(), r.end());
    l.insert(l.end(), r.begin(), r.end());
    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    e.resize(n);
    sz.resize(n);
    top.resize(n);
    in.resize(n);
    parent.resize(n);
    dep.resize(n);
    str.resize(2 * n);
    cin >> s;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    parent[0] = -1;
    dfsSize(0);
    dfs_now = 0;
    dfsHLD(0);
    buildSA();
    buildRMQ();
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a;
        --b;
        --c;
        --d;
        auto f = getPath(a, b), g = getPath(c, d);
        int j = 0, k = 0, ans = 0;
        while (j < f.size() && k < g.size()) {
            int len = min(lcp(f[j].first, g[k].first), min(f[j].second, g[k].second));
            ans += len;
            f[j].second -= len;
            g[k].second -= len;
            f[j].first += len;
            g[k].first += len;
            if (f[j].second > 0 && g[k].second > 0)
                break;
            if (f[j].second == 0)
                ++j;
            if (g[k].second == 0)
                ++k;
        }
        cout << ans << "\n";
    }
    return 0;
}