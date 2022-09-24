#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double dbl;

const ll INF = 1e12;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> t(n), h(n);
        vector<vector<int>> e(n);
        for (int i = 0; i < n; i++) scanf("%d", &t[i]);
        for (int i = 0; i < n; i++) scanf("%d", &h[i]);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        // 0 -- no edge
        // 1 -- t[p[v]] < t[v]
        // 2 -- t[p[v]] > t[v]
        vector<vector<ll>> dp(n, vector<ll>(3, INF));

        auto solve = [&](vector<pair<ll, ll>> cdp, int cost) {
            ll res = INF;
            sort(cdp.begin(), cdp.end(), [&](const pair<ll, ll> &x, const pair<ll, ll> &y) {
               return x.second - x.first < y.second - y.first;
            });
            ll cur = 0;
            for (auto o : cdp) cur += o.first;

            for (int c = 0; c <= (int)cdp.size(); c++) {
                int paths = cdp.size();
                paths -= min(c, (int)cdp.size() - c);
                res = min(res, cur + 1LL * paths * cost);

                if (c < (int)cdp.size()) {
                    cur += cdp[c].second - cdp[c].first;
                }
            }
            return res;
        };

        function<void(int, int)> dfs = [&](int v, int pr) {
            vector<pair<ll, ll>> cdp;
            for (int to : e[v]) {
                if (to == pr) continue;
                dfs(to, v);
                cdp.emplace_back(dp[to][1], dp[to][2]);
            }

            if (pr != -1) dp[v][0] = INF;
            else {
                auto cpy = cdp;
//                cpy.emplace_back(-t[v], -t[v]);
                dp[v][0] = solve(cpy, t[v]);
            }

            if (h[pr] > h[v]) dp[v][1] = INF;
            else {
                auto cpy = cdp;
                cpy.emplace_back(INF, 0);
                dp[v][1] = solve(cpy, t[v]);
            }

            if (h[pr] < h[v]) dp[v][2] = INF;
            else {
                auto cpy = cdp;
                cpy.emplace_back(0, INF);
                dp[v][2] = solve(cpy, t[v]);
            }
        };
        dfs(0, -1);

        printf("%lld\n", dp[0][0]);
    }

    return 0;
}