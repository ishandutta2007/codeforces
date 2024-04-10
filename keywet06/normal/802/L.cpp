#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
using pii = std::pair<int, int>;

const int64 P = (int64)1e9 + 7;

int64 add(int64 x, int64 y) { return (x += y) >= P ? x - P : x; }

int64 sub(int64 x, int64 y) { return (x -= y) < 0 ? x + P : x; }

int64 mult(int64 x, int64 y) { return (x * y) % P; }

int64 power(int64 x, int64 p) {
    if (p == 0) return 1;
    if (p & 1) return mult(x, power(x, p - 1));
    return power(mult(x, x), p / 2);
}

int64 rev(int64 x) { return power(x, P - 2); }

const int N = 200005;

int n;

int64 a[N][2];

vector<pii> g[N];

void dfs(int v, int par) {
    if ((int)g[v].size() == 1) {
        a[v][0] = a[v][1] = 0;
        return;
    }
    int64 p = (int)g[v].size();
    int64 q = 0;
    for (pii e : g[v]) q = add(q, e.second);
    for (pii e : g[v]) {
        int u = e.first;
        if (u == par) continue;
        dfs(u, v);
        p = sub(p, a[u][0]);
        q = add(q, a[u][1]);
    }
    if (p == 0) throw;
    p = rev(p);
    a[v][0] = p;
    a[v][1] = mult(q, p);
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int v, u, w;
        scanf("%d %d %d", &v, &u, &w);
        g[v].push_back(std::make_pair(u, w));
        g[u].push_back(std::make_pair(v, w));
    }
    for (pii e : g[0]) dfs(e.first, 0);
    int64 p = (int)g[0].size();
    int64 q = 0;
    for (pii e : g[0]) q = add(q, e.second);
    for (pii e : g[0]) {
        int u = e.first;
        p = sub(p, a[u][0]);
        q = add(q, a[u][1]);
    }
    if (p == 0) throw;
    printf("%lld\n", mult(q, rev(p)));
    return 0;
}