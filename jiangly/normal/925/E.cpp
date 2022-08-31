#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
constexpr int N = 100'000, LIMIT = 50, INF = N;
int n, m, clk, ans;
int parent[N], t[N], deg[N], sz[N], top[N], in[N], len[N], a[N], sorted[N], head[N], tail[N], tag[N], ftail[N], poi[N], cnt[4 * N];
std::vector<int> e[N];
std::pair<int, int> f[N];
void dfsSize(int u) {
    sz[u] = 1;
    for (int &v : e[u]) {
        dfsSize(v);
        sz[u] += sz[v];
        if (sz[v] > sz[e[u].front()])
            std::swap(v, e[u].front());
    }
}
void build(int l) {
    ftail[l] = l;
    poi[l] = -1;
    for (int i = l; i < tail[l]; ) {
        int j = i;
        while (j < tail[l] && sorted[j] == sorted[i])
            ++j;
        if (tag[l] + sorted[i] > 0 && poi[l] == -1)
            poi[l] = ftail[l];
        f[ftail[l]++] = {sorted[i], j - i};
        i = j;
    }
    if (poi[l] == -1)
        poi[l] = ftail[l];
}
void dfsHLD(int u) {
    ++len[top[u]];
    in[u] = clk++;
    a[in[u]] = -t[u];
    for (int v : e[u]) {
        if (v == e[u].front()) {
            top[v] = top[u];
        } else {
            top[v] = v;
        }
        dfsHLD(v);
    }
}
void rangeAdd(int h, int l, int r) {
    for (int i = l; i < r; ++i) {
        if (a[i] + tag[h] == 0)
            ++ans;
        ++cnt[a[i] + 2 * N];
        ++a[i];
    }
    for (int i = tail[h] - 1; i >= h; --i) {
        if (cnt[sorted[i] + 2 * N] > 0) {
            --cnt[sorted[i] + 2 * N];
            ++sorted[i];
        }
    }
    build(h);
}
void rangeMinus(int h, int l, int r) {
    for (int i = l; i < r; ++i) {
        ++cnt[a[i] + 2 * N];
        --a[i];
        if (a[i] + tag[h] == 0)
            --ans;
    }
    for (int i = h; i < tail[h]; ++i) {
        if (cnt[sorted[i] + 2 * N] > 0) {
            --cnt[sorted[i] + 2 * N];
            --sorted[i];
        }
    }
    build(h);
}
void insert(int u) {
    if (len[top[u]] <= LIMIT) {
        if (a[in[u]] > 0)
            --ans;
        a[in[u]] -= INF;
    } else {
        if (a[in[u]] + tag[head[in[u]]] > 0)
            --ans;
        int r = std::lower_bound(sorted + head[in[u]], sorted + tail[in[u]], a[in[u]]) - sorted;
        a[in[u]] -= INF;
        int l = std::upper_bound(sorted + head[in[u]], sorted + tail[in[u]], a[in[u]]) - sorted;
        for (int i = r - 1; i >= l; --i)
            sorted[i + 1] = sorted[i];
        sorted[l] = a[in[u]];
    }
    while (u != -1) {
        int l = in[top[u]], r = in[u];
        if (len[top[u]] <= LIMIT) {
            for (int i = l; i <= r; ++i) {
                if (a[i] == 0)
                    ++ans;
                ++a[i];
            }
        } else {
            rangeAdd(head[r], head[r], r + 1);
            for (int i = l; i != head[r]; i = tail[i]) {
                if (poi[i] != i && f[poi[i] - 1].first + tag[i] == 0) {
                    --poi[i];
                    ans += f[poi[i]].second;
                }
                ++tag[i];
            }
        }
        u = parent[top[u]];
    }
}
void erase(int u) {
    if (len[top[u]] <= LIMIT) {
        a[in[u]] += INF;
        if (a[in[u]] > 0)
            ++ans;
    } else {
        int l = std::upper_bound(sorted + head[in[u]], sorted + tail[in[u]], a[in[u]]) - sorted - 1;
        a[in[u]] += INF;
        int r = std::lower_bound(sorted + head[in[u]], sorted + tail[in[u]], a[in[u]]) - sorted - 1;
        for (int i = l; i < r; ++i)
            sorted[i] = sorted[i + 1];
        sorted[r] = a[in[u]];
        if (a[in[u]] + tag[head[in[u]]] > 0)
            ++ans;
    }
    while (u != -1) {
        int l = in[top[u]], r = in[u];
        if (len[top[u]] <= LIMIT) {
            for (int i = l; i <= r; ++i) {
                --a[i];
                if (a[i] == 0)
                    --ans;
            }
        } else {
            rangeMinus(head[r], head[r], r + 1);
            for (int i = l; i != head[r]; i = tail[i]) {
                --tag[i];
                if (poi[i] != ftail[i] && f[poi[i]].first + tag[i] == 0) {
                    ans -= f[poi[i]].second;
                    ++poi[i];
                }
            }
        }
        u = parent[top[u]];
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    parent[0] = -1;
    for (int i = 1; i < n; ++i) {
        std::cin >> parent[i];
        --parent[i];
        ++deg[parent[i]];
    }
    for (int i = 0; i < n; ++i)
        e[i].reserve(deg[i]);
    for (int i = 1; i < n; ++i)
        e[parent[i]].push_back(i);
    for (int i = 0; i < n; ++i)
        std::cin >> t[i];
    dfsSize(0);
    dfsHLD(0);
    std::copy(a, a + n, sorted);
    for (int i = 0; i < n; ++i) {
        if (i == top[i] && len[i] > LIMIT) {
            int b = sqrt(len[i] / 2);
            for (int j = in[i]; j < in[i] + len[i]; j += b) {
                int r = std::min(j + b, in[i] + len[i]);
                for (int k = j; k < r; ++k) {
                    head[k] = j;
                    tail[k] = r;
                }
                std::sort(sorted + j, sorted + r);
                build(j);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int u;
        std::cin >> u;
        if (u > 0) {
            --u;
            insert(u);
        } else {
            u = -u - 1;
            erase(u);
        }
        std::cout << ans << " \n"[i == m - 1];
    }
    return 0;
}