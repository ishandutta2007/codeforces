#include <bits/stdc++.h>

int n, k, ans;

std::string s;

std::vector<int> fa, d, c0, c1;

std::vector<std::vector<int>> belong;

int find(int u) {
    if (u == fa[u]) return u;
    int p = find(fa[u]);
    d[u] ^= d[fa[u]];
    fa[u] = fa[fa[u]];
    return fa[u];
}

int get(int x) {
    assert(c0[x] != -1 || c1[x] != -1);
    if (c0[x] == -1) {
        return c1[x];
    } else if (c1[x] == -1) {
        return c0[x];
    } else {
        return std::min(c0[x], c1[x]);
    }
}

void merge(int u, int v, int x) {
    find(u);
    x ^= d[u];
    u = fa[u];
    find(v);
    x ^= d[v];
    v = fa[v];
    if (u == v) {
        assert(x == 0);
    } else {
        ans -= get(u) + get(v);
        if (x == 1) std::swap(c0[v], c1[v]);
        if (c0[u] == -1 || c0[v] == -1) {
            c0[u] = -1;
        } else {
            c0[u] += c0[v];
        }
        if (c1[u] == -1 || c1[v] == -1) {
            c1[u] = -1;
        } else {
            c1[u] += c1[v];
        }
        fa[v] = u;
        d[v] = x;
        ans += get(u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k >> s;
    fa.resize(k);
    d.resize(k);
    c0.assign(k, 1);
    c1.resize(k);
    belong.resize(n);
    std::iota(fa.begin(), fa.end(), 0);
    for (int i = 0; i < k; ++i) {
        int s;
        std::cin >> s;
        for (int j = 0; j < s; ++j) {
            int x;
            std::cin >> x;
            --x;
            belong[x].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (int(belong[i].size()) == 0) {
            assert(s[i] == '1');
        } else if (int(belong[i].size()) == 1) {
            int u = belong[i][0];
            find(u);
            int x = (s[i] - '0') ^ d[u] ^ 1;
            u = fa[u];
            ans -= get(u);
            if (x == 0) {
                c0[u] = -1;
            } else {
                c1[u] = -1;
            }
            ans += get(u);
        } else {
            merge(belong[i][0], belong[i][1], (s[i] - '0') ^ 1);
        }
        std::cout << ans << "\n";
    }
    return 0;
}