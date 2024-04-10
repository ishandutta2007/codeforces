#include <bits/stdc++.h>

constexpr int64_t P = 1000000000039;

constexpr int N = 2e4;

int cnt;
int trie[N][26], trieCnt[N], trieSize[N], trieAns[N];
std::unordered_map<int64_t, int> id;

void initTrie() {
    std::memset(trie, 0, cnt * 26 * sizeof(int));
    std::memset(trieCnt, 0, cnt * sizeof(int));
    std::memset(trieSize, 0, cnt * sizeof(int));
    id.clear();
    id[0] = 0;
    cnt = 1;
}

void prepare() {
    for (int i = cnt - 1; i >= 0; --i) {
        trieSize[i] = trieCnt[i];
        for (int j = 0; j < 26; ++j) {
            if (trie[i][j] != 0) {
                trieSize[i] += trieSize[trie[i][j]];
            }
        }
    }
    trieAns[0] = 0;
    for (int i = 0; i < cnt; ++i) {
        int temp = trieAns[i] + trieCnt[i];
        for (int j = 0; j < 26; ++j) {
            if (trie[i][j] != 0) {
                trieAns[trie[i][j]] = temp;
                temp += trieSize[trie[i][j]];
            }
        }
    }
}

int64_t mul(int64_t a, int64_t b) {
    return __int128(a) * b % P;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    
    const int BASE = gen() % 1919810 + 114514;
    
    int n, q;
    std::cin >> n >> q;
    
    const int lg = std::__lg(n);
    
    std::vector<int64_t> pow(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pow[i] = pow[i - 1] * BASE % P;
    }
    
    std::vector<std::vector<std::pair<int, char>>> e(n);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        char c;
        std::cin >> u >> v >> c;
        --u, --v;
        e[u].emplace_back(v, c);
        e[v].emplace_back(u, c);
    }
    
    std::vector<std::vector<std::pair<int, int>>> queries(n);
    for (int i = 0; i < q; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        queries[x].emplace_back(y, i);
    }
    
    std::vector<int> ans(q);
    
    std::vector<bool> vis(n);
    std::vector<int> siz(n), dep(n);
    std::vector<std::vector<int>> p(n, std::vector<int>(lg + 1, -1));
    std::vector<std::vector<int64_t>> up(n, std::vector<int64_t>(lg + 1)), down(n, std::vector<int64_t>(lg + 1));
    
    std::function<void(int)> dfs0 = [&](int u) {
        for (int i = 1; (1 << i) <= dep[u]; ++i) {
            int pp = p[u][i - 1];
            p[u][i] = p[pp][i - 1];
            up[u][i] = (mul(up[u][i - 1], pow[1 << (i - 1)]) + up[pp][i - 1]) % P;
            down[u][i] = (mul(down[pp][i - 1], pow[1 << (i - 1)]) + down[u][i - 1]) % P;
        }
        for (auto [v, c] : e[u]) {
            if (v == p[u][0]) {
                continue;
            }
            p[v][0] = u;
            up[v][0] = down[v][0] = c;
            dep[v] = dep[u] + 1;
            dfs0(v);
        }
    };
    dfs0(0);
    
    std::function<int(int, int, int)> findCentroid = [&](int u, int p, int s) {
        for (auto [v, c] : e[u]) {
            if (!vis[v] && v != p && 2 * siz[v] > s) {
                return findCentroid(v, u, s);
            }
        }
        return u;
    };
    
    std::function<void(int, int)> dfs1 = [&](int u, int p) {
        siz[u] = 1;
        for (auto [v, c] : e[u]) {
            if (vis[v] || v == p) {
                continue;
            }
            dfs1(v, u);
            siz[u] += siz[v];
        }
    };
    
    std::function<void(int, int, int, int64_t)> buildTrie = [&](int u, int p, int t, int64_t h) {
        ++trieCnt[t];
        for (auto [v, c] : e[u]) {
            if (vis[v] || v == p) {
                continue;
            }
            if (trie[t][c - 'a'] == 0) {
                id[(h * BASE + c) % P] = cnt;
                trie[t][c - 'a'] = cnt++;
            }
            buildTrie(v, u, trie[t][c - 'a'], (h * BASE + c) % P);
        }
    };
    
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) {
            std::swap(u, v);
        }
        for (int i = lg; i >= 0; --i) {
            if (dep[u] - (1 << i) >= dep[v]) {
                u = p[u][i];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = lg; i >= 0; --i) {
            if (p[u][i] != p[v][i]) {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return p[u][0];
    };
    
    auto level = [&](int u, int d) {
        for (int i = lg; i >= 0; --i) {
            if (d >> i & 1) {
                u = p[u][i];
            }
        }
        return u;
    };
    
    auto getUpHash = [&](int u, int d) {
        int64_t h = 0;
        for (int i = lg; i >= 0; --i) {
            if (d >> i & 1) {
                h = (mul(h, pow[1 << i]) + up[u][i]) % P;
                u = p[u][i];
            }
        }
        return h;
    };
    
    auto getDownHash = [&](int u, int d) {
        const int x = u;
        int64_t h = 0;
        for (int i = lg; i >= 0; --i) {
            if (d >> i & 1) {
                h = (mul(down[u][i], pow[dep[x] - dep[u]]) + h) % P;
                u = p[u][i];
            }
        }
        return h;
    };
    
    auto lcp = [&](int u, int x, int y) {
        int l1 = lca(u, x);
        int l2 = lca(u, y);
        int len1 = dep[u] + dep[x] - 2 * dep[l1];
        int len2 = dep[u] + dep[y] - 2 * dep[l2];
        int l = 0, r = std::min(len1, len2);
        int64_t hl1 = getUpHash(u, dep[u] - dep[l1]);
        int64_t hl2 = getUpHash(u, dep[u] - dep[l2]);
        while (l < r) {
            int m = (l + r + 1) / 2;
            int64_t h1, h2;
            if (m <= dep[u] - dep[l1]) {
                h1 = getUpHash(u, m);
            } else {
                h1 = (mul(hl1, pow[m - (dep[u] - dep[l1])]) + getDownHash(level(x, len1 - m), m - (dep[u] - dep[l1]))) % P;
            }
            if (m <= dep[u] - dep[l2]) {
                h2 = getUpHash(u, m);
            } else {
                h2 = (mul(hl2, pow[m - (dep[u] - dep[l2])]) + getDownHash(level(y, len2 - m), m - (dep[u] - dep[l2]))) % P;
            }
            if (h1 == h2) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        if (l == len1) {
            return -1;
        }
        if (l != len2) {
            char c1, c2;
            if (l < dep[u] - dep[l1]) {
                c1 = up[level(u, l)][0];
            } else {
                c1 = up[level(x, len1 - l - 1)][0];
            }
            if (l < dep[u] - dep[l2]) {
                c2 = up[level(u, l)][0];
            } else {
                c2 = up[level(y, len2 - l - 1)][0];
            }
            if (c1 > c2) {
                return -2;
            } else {
                return -1;
            }
        }
        if (l <= dep[u] - dep[l1]) {
            return level(u, l);
        } else {
            return level(x, len1 - l);
        }
    };
    
    auto query = [&](int u, int v) {
        int x = lca(u, v);
        int64_t hl = getUpHash(u, dep[u] - dep[x]);
        int len = dep[u] + dep[v] - 2 * dep[x];
        int l = 0, r = len;
        while (l < r) {
            int m = (l + r + 1) / 2;
            int64_t h;
            if (m <= dep[u] - dep[x]) {
                h = getUpHash(u, m);
            } else {
                h = (mul(hl, pow[m - (dep[u] - dep[x])]) + getDownHash(level(v, len - m), m - (dep[u] - dep[x]))) % P;
            }
            if (id.find(h) != id.end()) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        int64_t h;
        if (l <= dep[u] - dep[x]) {
            h = getUpHash(u, l);
        } else {
            h = (mul(hl, pow[l - (dep[u] - dep[x])]) + getDownHash(level(v, len - l), l - (dep[u] - dep[x]))) % P;
        }
        int p = id[h];
        int res = trieAns[p];
        if (len != l) {
            char c;
            if (l < dep[u] - dep[x]) {
                c = up[level(u, l)][0];
            } else {
                c = up[level(v, len - l - 1)][0];
            }
            res += trieCnt[p];
            for (int i = 0; i < c - 'a'; ++i) {
                if (trie[p][i] != 0) {
                    res += trieSize[trie[p][i]];
                }
            }
        }
        return res;
    };
    
    std::function<void(int, int, int, int, int)> calc = [&](int u, int p, int c, int siz, int coef) {
        for (auto [v, i] : queries[u]) {
            int x = lcp(u, v, c);
            if (x == -1) {
                // do nothing
            } else if (x == -2) {
                ans[i] += coef * siz;
            } else {
                ans[i] += coef * query(x, v);
            }
        }
        for (auto [v, x] : e[u]) {
            if (vis[v] || v == p) {
                continue;
            }
            calc(v, u, c, siz, coef);
        }
    };
    
    std::function<void(int)> solve = [&](int u) {
        dfs1(u, -1);
        u = findCentroid(u, -1, siz[u]);
        vis[u] = true;
        dfs1(u, -1);
        
        initTrie();
        buildTrie(u, -1, 0, 0);
        prepare();
        calc(u, -1, u, siz[u], 1);
        
        for (auto [v, c] : e[u]) {
            if (vis[v]) {
                continue;
            }
            initTrie();
            trieCnt[0] = 0;
            trie[0][c - 'a'] = cnt++;
            id[c] = 1;
            buildTrie(v, u, 1, c);
            prepare();
            calc(v, u, u, siz[v], -1);
        }
        
        for (auto [v, c] : e[u]) {
            if (!vis[v]) {
                solve(v);
            }
        }
    };
    solve(0);
    
    for (int i = 0; i < q; ++i) {
        std::cout << ans[i] - 1 << "\n";
    }
    
    return 0;
}