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


const int INF = 1.01e9;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m, a, b;
    while (scanf("%d%d%d%d", &n, &m, &a, &b) == 4) {
        vector<pair<int, pair<int, int>>> ed(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &ed[i].second.first, &ed[i].second.second, &ed[i].first);
            ed[i].second.first--;
            ed[i].second.second--;
        }

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> get = [&](int x) {
            if (x == p[x]) return x;
            return p[x] = get(p[x]);
        };

        sort(ed.begin(), ed.end());
        for (int i = 0; i < m; i++) {
            if (ed[i].first == a) {
                int u = get(ed[i].second.first);
                int v = get(ed[i].second.second);
                p[v] = u;
            }
        }

        vector<pair<int, pair<int, int>>> ned;
        for (auto o : ed) {
            if (o.first == b && get(o.second.first) == get(o.second.second)) continue;
            ned.push_back(o);
        }
        ed = ned;

        vector<vector<pair<int, int>>> e(n);
        for (auto o : ed) {
            e[o.second.first].push_back({o.second.second, o.first});
            e[o.second.second].push_back({o.second.first, o.first});
        }

        vector<int> cnt(n);
        vector<vector<int>> sp(n);
        for (int i = 0; i < n; i++) {
            cnt[get(i)]++;
            sp[get(i)].push_back(i);
        }

        vector<int> vct;
        vector<int> id(n, -1);
        for (int i = 0; i < n; i++)
            if (cnt[i] >= 4 || get(0) == i) {
                id[i] = vct.size();
                vct.push_back(i);
            }


        vector<vector<int>> dp(1 << vct.size(), vector<int>(n, INF));
        int fmask = 0;
        if (id[get(0)] != -1) {
            fmask |= 1 << id[get(0)];
        }
        dp[fmask][0] = 0;

        vector<int> last(n);
        int tmr = 0;

        for (int mask = 0; mask < (1 << vct.size()); mask++) {
            tmr++;
            for (int it = 0; it < n; it++) {
                int u = -1;
                for (int t = 0; t < n; t++) if (last[t] != tmr && (u == -1 || dp[mask][t] < dp[mask][u])) u = t;
                last[u] = tmr;

                for (auto o : e[u]) {
                    int to = o.first;
                    int val = dp[mask][u] + o.second;
                    int nmask = mask;
                    if (id[get(to)] != -1) {
                        if (o.second == b && mask & (1 << id[get(to)])) continue;
                        nmask |= 1 << id[get(to)];
                    }
                    dp[nmask][to] = min(dp[nmask][to], val);
                }
            }
        }

        vector<int> ans(n, INF);
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < (1 << vct.size()); mask++) {
                ans[i] = min(ans[i], dp[mask][i]);
            }
        }
        for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}