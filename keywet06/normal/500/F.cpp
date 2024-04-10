#include <bits/stdc++.h>

const int N = 4010;

int c[N], h[N], t[N], nc[N], nh[N], nt[N], f[N];
int lto[N][N], rto[N][N];

std::pair<int, int> e[N];

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", c + i, h + i, t + i);
        e[i] = std::make_pair(t[i], i);
    }
    sort(e, e + n);
    for (int i = 0; i < n; ++i) {
        int id = e[i].second;
        nc[i] = c[id];
        nh[i] = h[id];
        nt[i] = t[id];
    }
    for (int i = 0; i < n; ++i) {
        c[i] = nc[i];
        h[i] = nh[i];
        t[i] = nt[i];
    }
    int Beg = 0;
    while (Beg < n) {
        int End = Beg;
        while (End + 1 < n && t[End + 1] / p == t[Beg] / p) ++End;
        {
            for (int j = 0; j < N; ++j) {
                f[j] = 0;
            }
            for (int id = Beg; id <= End; ++id) {
                for (int j = N - 1 - c[id]; j >= 0; --j) {
                    if (f[j] + h[id] > f[j + c[id]]) f[j + c[id]] = f[j] + h[id];
                }
                for (int j = 0; j < N; ++j) lto[id][j] = f[j];
            }
        }
        {
            for (int j = 0; j < N; ++j) f[j] = 0;
            for (int id = End; id >= Beg; --id) {
                for (int j = N - 1 - c[id]; j >= 0; --j) {
                    if (f[j] + h[id] > f[j + c[id]]) f[j + c[id]] = f[j] + h[id];
                }
                for (int j = 0; j < N; ++j) rto[id][j] = f[j];
            }
        }
        Beg = End + 1;
    }
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int foo, bar;
        scanf("%d %d", &foo, &bar);
        int first = -1, last = -1;
        for (int i = 0; i < n; ++i) {
            if (t[i] <= foo && foo <= t[i] + p - 1) {
                if (first == -1) first = i;
                last = i;
            }
        }
        if (first == -1) {
            printf("%d\n", 0);
            continue;
        }
        if (t[first] / p == foo / p) {
            printf("%d\n", lto[last][bar]);
            continue;
        }
        if (t[last] / p == foo / p - 1) {
            printf("%d\n", rto[first][bar]);
            continue;
        }
        int ans = 0;
        for (int part = 0; part <= bar; ++part) {
            int cur = lto[last][part] + rto[first][bar - part];
            if (cur > ans) ans = cur;
        }
        printf("%d\n", ans);
    }
    return 0;
}