#include <bits/stdc++.h>
constexpr int N = 2e5;
int n, m;
std::string s[N];
std::vector<int> e[N];
int dfx;
int rt[N], parent[N], in[N], out[N];
void addEdge(int u, int v) {
    e[u].push_back(v);
    e[v].push_back(u);
}
void dfs(int u) {
    in[u] = dfx++;
    for (auto v : e[u]) {
        if (v == parent[u])
            continue;
        rt[v] = rt[u];
        parent[v] = u;
        dfs(v);
    }
    out[u] = dfx;
}
struct Line {
    int x, y1, y2, v;
    Line() {}
    Line(int x, int y1, int y2, int v) : x(x), y1(y1), y2(y2), v(v) {}
} line[4 * N];
int cnt;
void work(int u, int v, std::vector<std::pair<int, int>> &a) {
    if (parent[u] == v) {
        a.emplace_back(in[u], out[u]);
    } else {
        int r = rt[u];
        a.emplace_back(in[r], in[v]);
        a.emplace_back(out[v], out[r]);
    }
}
void work(int u, std::vector<std::pair<int, int>> &a) {
    int r = rt[u];
    a.emplace_back(in[r], out[r]);
}
struct Node {
    int tag, len;
} t[4 * N];
void rangeAdd(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x) {
        return;
    } else if (l >= x && r <= y) {
        t[p].tag += v;
        t[p].len = t[p].tag ? r - l : r - l == 1 ? 0 : t[2 * p].len + t[2 * p + 1].len;
    } else {
        int m = (l + r) / 2;
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        t[p].len = t[p].tag ? r - l : t[2 * p].len + t[2 * p + 1].len;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
        std::cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'L') {
                if (j)
                    addEdge(i * m + j - 1, i * m + j + 1);
                if (j + 2 < m)
                    addEdge(i * m + j, i * m + j + 2);
            } else if (s[i][j] == 'U') {
                if (i)
                    addEdge((i - 1) * m + j, (i + 1) * m + j);
                if (i + 2 < n)
                    addEdge(i * m + j, (i + 2) * m + j);
            }
        }
    }
    for (int i = 0; i < n * m; ++i)
        parent[i] = -1;
    for (int i = 0; i < n * m; ++i) {
        if (parent[i] == -1) {
            rt[i] = i;
            dfs(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::vector<std::pair<int, int>> u, v;
            if (s[i][j] == 'L') {
                if (j) {
                    work(i * m + j + 1, i * m + j - 1, u);
                } else {
                    work(i * m + j + 1, u);
                }
                if (j + 2 < m) {
                    work(i * m + j, i * m + j + 2, v);
                } else {
                    work(i * m + j, v);
                }
            } else if (s[i][j] == 'U') {
                if (i) {
                    work((i + 1) * m + j, (i - 1) * m + j, u);
                } else {
                    work((i + 1) * m + j, u);
                }
                if (i + 2 < n) {
                    work(i * m + j, (i + 2) * m + j, v);
                } else {
                    work(i * m + j, v);
                }
            }
            if ((i ^ j) & 1)
                std::swap(u, v);
            for (auto x : u) {
                for (auto y : v) {
                    line[cnt++] = Line(x.first, y.first, y.second, 1);
                    line[cnt++] = Line(x.second, y.first, y.second, -1);
                }
            }
        }
    }
    std::sort(line, line + cnt, [&](const auto &lhs, const auto &rhs) {return lhs.x < rhs.x;});
    long long ans = 0;
    for (int i = 0; i < cnt - 1; ++i) {
        rangeAdd(1, 0, n * m, line[i].y1, line[i].y2, line[i].v);
        ans += 1ll * (line[i + 1].x - line[i].x) * t[1].len;
    }
    std::cout << ans << "\n";
    return 0;
}