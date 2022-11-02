#include <bits/stdc++.h>

const int N = 100054, M = 450;

int n;
int a[N], succ[N];
int sg[N], right[N];
bool marked[M];

inline int min(const int x, const int y) { return x < y ? x : y; }
inline int max(const int x, const int y) { return x < y ? y : x; }

struct DSU {
    int p[N], w[N];

    inline void resize(int n) { std::iota(p, p + (n + 1), 0), memset(w, -1, (n + 1) << 2); }
    int ancestor(int x) { return p[x] == x ? x : (p[x] = ancestor(p[x])); }
    void fill(int l, int r, int x) {
        for (int i = ancestor(l); i < r; i = p[i] = ancestor(i + 1)) w[i] = x;
    }
} dsu[M];

int work() {
    int i, j, l, r, w;
    std::cin >> n, memset(succ, -1, sizeof succ);
    for (i = 0; i < n; ++i) std::cin >> a[i], succ[a[i]] = i;
    for (i = N - 2; i >= 0; --i) {
        if (!~succ[i]) succ[i] = succ[i + 1];
    }
    sg[n - 1] = 0;
    for (i = 1; i < M; ++i) dsu[i].resize(n);
    for (i = n - 2; i >= 0; --i) {
        right[1] = n - 1;
        for (j = 1; ~(w = dsu[j].w[i]); ++j) right[j + 1] = min(right[j], w);
        for (sg[i] = j, r = i; j; --j, r = l) l = succ[max(2 * a[i] - a[right[j]] + 1, 0)], dsu[j].fill(l, r, i);
    }
    memset(marked, false, sizeof marked);
    for (i = 0; i < n; ++i) marked[sg[i]] = true;
    i = 0;
    while (marked[i]) ++i;
    return i;
}

int main() {
    int T, sg = 0;
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    for (std::cin >> T; T; --T) sg ^= work();
    std::cout << (sg ? "YES\n" : "NO\n");
    return 0;
}