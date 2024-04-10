#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<vector<int>> e(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        struct item {
            int cnt[2];
            ll sum[2];

            item() {
                memset(cnt, 0, sizeof(cnt));
                memset(sum, 0, sizeof(sum));
            }
        };
        ll ans = 0;
        function<item(int, int)> dfs = [&](int v, int pr) {
            item cur = item();
            cur.cnt[0]++;

            for (int to : e[v]) {
                if (to == pr) continue;
                item nw = dfs(to, v);

                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        ll t = cur.sum[i] * nw.cnt[j] + nw.sum[j] * cur.cnt[i];
                        if ((i + j) % 2) {
                            t += 1LL * cur.cnt[i] * nw.cnt[j];
                        }
                        assert(t % 2 == 0);
                        ans += t / 2;
                    }
                }

                for (int i = 0; i < 2; i++) {
                    cur.sum[i] += nw.sum[i];
                    cur.cnt[i] += nw.cnt[i];
                }
            }
            cur.sum[0] += cur.cnt[0];
            cur.sum[1] += cur.cnt[1];
            swap(cur.sum[0], cur.sum[1]);
            swap(cur.cnt[0], cur.cnt[1]);
            return cur;
        };
        dfs(0, -1);
        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}