#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5 + 100;
vector<array<int, 2>> g[MAXN];
int val[MAXN];

int h;

bool dfs(int v, int cur = 0) {
    val[v] = cur;
    for (auto e : g[v]) {
        int u = e[0], w = e[1];
        if (val[u] == -1) {
            if (!dfs(u, (w - cur + h) % h)) return false;
        } else if (val[u] != (w - cur + h) % h) {
            return false;
        }
    }
    return true;
}

const int MOD = 1e9 + 7;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m >> h;
        for (int i = 0; i < n + m; ++i) {
            g[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int c;
                cin >> c;
                if (c != -1) {
                    g[i].push_back({j + n, c});
                    g[j + n].push_back({i, c});
                }
            }
        }
        fill(val, val + n + m, -1);
        int cnt = -1;
        for (int i = 0; i < n + m; ++i) {
            if (val[i] == -1) {
                /// cout << i << endl;
                if (dfs(i)) {
                    cnt++;
                } else {
                    cnt = -MOD;
                    break;
                }
            }
        }
        if (cnt < -1) {
            cout << 0 << endl;
        } else {
            int ans = 1;
            for (int i = 0; i < cnt; ++i) {
                ans = (ans * h) % MOD;
            }
            cout << ans << endl;
        }
    }
    return 0;
}