#include <bits/stdc++.h>

using int64 = long long;

const int N = 300005;

int n, m, i, tot;
int fir[N], ne[N], la[N], px[N], py[N], c[N], F[N];

int64 o;
int64 v[N], S[4], e[N];

void ins(int x, int y) { la[++tot] = y, ne[tot] = fir[x], fir[x] = tot; }

void dfs(int x) {
    S[c[x]] += v[x];
    for (int i = fir[x], y; i; i = ne[i]) {
        if (y = la[i], !c[y]) F[y] = x, c[y] = 3 - c[x], dfs(y);
    }
}

void dfs2(int x) {
    for (int i = fir[x], y; i; i = ne[i]) {
        if (F[y = la[i]] == x) dfs2(y), e[(i + 1) / 2] = v[y], v[x] -= v[y];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> v[i];
    for (int i = 1; i <= m; ++i) std::cin >> px[i] >> py[i], ins(px[i], py[i]), ins(py[i], px[i]);
    c[1] = 1;
    dfs(1);
    for (int i = 1; i <= m; ++i) {
        if (c[px[i]] == c[py[i]]) {
            o = (S[c[px[i]]] - S[3 - c[px[i]]]) / 2;
            v[px[i]] -= o;
            v[py[i]] -= o;
            S[c[px[i]]] -= o * 2;
            e[i] = o;
            break;
        }
    }
    if (S[1] != S[2]) return std::cout << "NO" << '\n', 0;
    std::cout << "YES" << '\n';
    dfs2(1);
    for (int i = 1; i <= m; ++i) std::cout << e[i] << '\n';
    return 0;
}