#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;
const int MOD = (int)1e9 + 7;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i], &b[i]);
            a[i]--; b[i]--;
        }

        vector<int> nxt(2 * n, -1);
        vector<vector<int> > e(2 * n);
        vector<vector<int> > g(2 * n);
        for (int i = 0; i < n; i++) {
            nxt[a[i]] = b[i];
            e[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
        vector<int> c(2 * n);

        function<int(int)> dfs = [&](int v) {
            if (c[v] != 0) return 0;
            c[v] = 2;
            int ans = 1;
            for (int to : g[v]) ans += dfs(to);
            return ans;
        };

        int ans = 1;
        for (int i = 0; i < 2 * n; i++) {
            if (e[i].empty() && !g[i].empty()) {
                ans = 1LL * ans * dfs(i) % MOD;
            }
        }

        for (int i = 0; i < 2 * n; i++) {
            if (nxt[i] == -1) continue;
            if (c[i] != 0) continue;

            int v = i;
            while (v != -1) {
                if (c[v] != 0) break;
                c[v] = 1;
                v = nxt[v];
            }
            assert(v != -1);
            if (c[v] == 1) {
                int len = 0;
                while (c[v] == 1) {
                    c[v] = 2;
                    v = nxt[v];
                    len++;
                }
                if (len > 1) ans = 2LL * ans % MOD;
            }
            bool need = 1;
            v = i;
            while (c[v] == 1) {
                c[v] = 2;
                v = nxt[v];
            }
        }
        printf("%d\n", ans);
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}