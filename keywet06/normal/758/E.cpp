#include <bits/stdc++.h>

typedef long long int64;

const int N = 2e5 + 5;

int n;
int X[N], Y[N], W[N], S[N], dep[N], t[N];

int64 tot[N], c[N];

std::vector<std::pair<int, int> > e[N];

std::set<std::pair<int, int> > H[N];

void add(int x, int w) {
    for (int i = x; i <= n; i += i & -i) {
        c[i] += w;
    }
}
int64 get(int x) {
    int64 res = 0;
    while (x > 0) {
        res += c[x];
        x &= x - 1;
    }
    return res;
}

int ncnt, L[N], R[N];

void dfs(int x) {
    L[x] = ++ncnt;
    for (auto &it : e[x]) {
        int y = it.first;
        int z = it.second;
        dep[y] = dep[x] + 1;
        t[y] = z;
        dfs(y);
        tot[x] += tot[y];
        if (H[x].size() < H[y].size()) {
            H[x].swap(H[y]);
        }
        H[x].insert(H[y].begin(), H[y].end());
        std::set<std::pair<int, int> > T;
        T.swap(H[y]);
    }
    R[x] = ncnt;
    if (x == 1) return;
    while (tot[x] > S[t[x]]) {
        if (H[x].empty()) {
            puts("-1");
            exit(0);
        }
        auto it = *H[x].rbegin();
        H[x].erase(it);
        int y = it.second;
        int delta = std::min(tot[x] - S[t[x]], std::min(W[t[y]] - 1LL, S[t[y]] - get(R[y]) + get(L[y])));
        if (delta == 0) continue;
        tot[x] -= delta;
        W[t[y]] -= delta;
        add(L[y], -delta);
        S[t[y]] -= delta;
        if (W[t[y]] > 1) {
            H[x].insert({dep[y], y});
        }
    }
    if (W[t[x]] > 1) H[x].insert({dep[x], x});
    add(L[x], W[t[x]]);
    tot[x] += W[t[x]];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d%d", X + i, Y + i, W + i, S + i);
        e[X[i]].push_back({Y[i], i});
    }
    dfs(1);
    printf("%d\n", n);
    for (int i = 1; i < n; ++i) printf("%d %d %d %d\n", X[i], Y[i], W[i], S[i]);
    return 0;
}