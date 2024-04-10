#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 13;

int n, m;
long long d[N][2][2];

vector<pair<int, int>> g[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        --v;
        --u;
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) d[i][j][k] = (long long)1e18;

    d[0][0][0] = 0;
    set<pair<long long, array<int, 3>>> q;
    q.insert({0, {0, 0, 0}});

    while (!q.empty()) {
        auto [v, mx, mn] = q.begin()->second;
        q.erase(q.begin());
        for (auto [u, w] : g[v]) {
            for (int i = 0; i <= 1 - mx; i++) {
                for (int j = 0; j <= 1 - mn; j++) {
                    if (d[u][mx | i][mn | j] > d[v][mx][mn] + (1 - i + j) * w) {
                        auto it =
                            q.find({d[u][mx | i][mn | j], {u, mx | i, mn | j}});
                        if (it != q.end()) q.erase(it);
                        d[u][mx | i][mn | j] = d[v][mx][mn] + (1 - i + j) * w;
                        q.insert({d[u][mx | i][mn | j], {u, mx | i, mn | j}});
                    }
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        printf("%lld ", d[i][1][1]);
    }
    puts("");
}