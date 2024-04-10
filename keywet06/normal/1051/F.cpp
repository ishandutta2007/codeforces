#include <bits/stdc++.h>

#define fi first
#define se second

using int64 = long long;
using pair = std::pair<int, int>;

const int K = 23;
const int D = K << 1;
const int N = 100005;
const int64 INF = int64(1e18);

int n, m, q, cnt, ccnt;
int p[D];
int v[N];
int sp[N][K];

int64 d[D];
int64 dep[N], dp[N];
int64 ad[D][D];
std::vector<pair> e[N], t[N];

void g(int x, int y) {
    v[x] = ++ccnt;
    for (pair i : e[x]) {
        if (i.fi == y) continue;
        if (!v[i.fi]) {
            t[x].push_back(i);
            g(i.fi, x);
        } else if (v[i.fi] < v[x]) {
            cnt += 2;
            p[cnt - 2] = x;
            p[cnt - 1] = i.fi;
            ad[cnt - 2][cnt - 1] = ad[cnt - 1][cnt - 2] = i.se;
        }
    }
}

void f(int x, int y, int z, int64 d) {
    dep[x] = d;
    dp[x] = z;
    sp[x][0] = y;
    for (int i = 1; i < K; ++i) sp[x][i] = sp[sp[x][i - 1]][i - 1];
    for (pair i : t[x]) {
        if (i.fi == y) continue;
        f(i.fi, x, z + 1, d + i.se);
    }
}

int64 l(int x, int y) {
    if (dp[x] < dp[y]) std::swap(x, y);
    int64 dx = dep[x], dy = dep[y];
    for (int i = K - 1; i >= 0; --i) {
        if (dp[x] - (1 << i) >= dp[y]) x = sp[x][i];
    }
    if (x == y) return dx - dep[x];
    for (int i = K - 1; i >= 0; --i) {
        if (sp[x][i] != sp[y][i]) 
            x = sp[x][i],
            y = sp[y][i];
    }
    return dx + dy - 2 * dep[sp[x][0]];
}

int64 di(int x, int y) {
    std::fill(d, d + cnt, INF);
    std::fill(v, v + cnt, 0);
    d[x] = 0;
    for (int c = x;;) {
        if (c == y) return d[c];
        v[c] = 1;
        for (int i = 0; i < cnt; ++i) d[i] = std::min(d[i], d[c] + ad[c][i]);
        int mi = -1;
        for (int i = 0; i < cnt; ++i) {
            if (!v[i] && (mi == -1 || d[i] < d[mi])) mi = i;
        }
        c = mi;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0, x, y, z; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    for (int i = 0; i < D; ++i) {
        std::fill(ad[i], ad[i] + D, INF);
        ad[i][i] = 0;
    }
    g(1, 0);
    f(1, 0, 0, 0);
    for (int i = 0; i < cnt; ++i) {
        for (int j = i + 1; j < cnt; ++j) {
            ad[i][j] = ad[j][i] = std::min(ad[i][j], l(p[i], p[j]));
        }
    }
    scanf("%d", &q);
    cnt += 2;
    for (int x, y; q--;) {
        scanf("%d%d", &x, &y);
        p[cnt - 2] = x;
        p[cnt - 1] = y;
        for (int i = 0; i < cnt - 2; ++i) {
            ad[i][cnt - 2] = ad[cnt - 2][i] = l(p[i], x);
            ad[i][cnt - 1] = ad[cnt - 1][i] = l(p[i], y);
        }
        ad[cnt - 2][cnt - 1] = ad[cnt - 1][cnt - 2] = l(x, y);
        printf("%lld\n", di(cnt - 2, cnt - 1));
    }
}