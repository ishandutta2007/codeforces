#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, s, t, eu[N], ev[N], anc[N], cnt[N];
long long ans, ant;
bool fs[N], ft[N];

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); s = read(); t = read();
        for (int i = 0; i < m; i++) { eu[i] = read(); ev[i] = read(); }
        for (int u = 1; u <= n; u++) { anc[u] = u; }
        for (int i = 0; i < m; i++) {
            int u = eu[i], v = ev[i];
            if (u == s || u == t || v == s || v == t) { continue; }
            if (find(u) != find(v)) {
                anc[find(u)] = find(v);
            }
        }
        for (int u = 1; u <= n; u++) { fs[u] = ft[u] = false; cnt[u] = 0; }
        for (int i = 0; i < m; i++) {
            int u = eu[i], v = ev[i];
            if (u == s || u == t) { std::swap(u, v); }
            if (u == s || u == t) { continue; }
            if (v == s) { fs[find(u)] = true; }
            if (v == t) { ft[find(u)] = true; }
        }
        for (int u = 1; u <= n; u++) { cnt[find(u)]++; }
        ans = ant = 0;
        for (int u = 1; u <= n; u++) {
            if (find(u) != u) { continue; }
            if (fs[u] && ft[u]) { continue; }
            if (fs[u]) { ans += cnt[u]; }
            if (ft[u]) { ant += cnt[u]; }
        }
        printf("%I64d\n", ans * ant);
    }
    return 0;
}