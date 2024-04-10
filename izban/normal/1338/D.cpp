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
typedef long double ld;

int solve(vector<vector<int>> e) {
    int n = e.size();

    struct dp_subtree {
        int start_root{0};
        int start_subtree{0};
    };

    struct dp_forest {
        int start_any_root{0};
        int start_any_subtree{0};
        int count{0};

        dp_forest() {}
        dp_forest(dp_subtree d) {
            start_any_root = d.start_root;
            start_any_subtree = d.start_subtree;
            count = 1;
        }

        dp_subtree add_root() const {
            dp_subtree res;
            res.start_root = start_any_subtree + 1;
            res.start_subtree = max(start_any_root, start_any_subtree) + max(count - 1, 0);
            return res;
        }
    };

    auto merge = [&](dp_forest a, dp_forest b) {
        a.count += b.count;
        a.start_any_root = max(a.start_any_root, b.start_any_root);
        a.start_any_subtree = max(a.start_any_subtree, b.start_any_subtree);
        return a;
    };

    vector<dp_subtree> dp(n);

    auto recalc_dp = [&](int v, int pr) {
        dp_forest d;
        for (int to : e[v]) {
            if (to == pr) continue;
            d = merge(d, dp[to]);
        }
        dp[v] = d.add_root();
    };

    function<void(int, int)> dfs1 = [&](int v, int pr) {
        for (int to : e[v]) {
            if (to == pr) continue;
            dfs1(to, v);
        }
        recalc_dp(v, pr);
    };
    dfs1(0, -1);

    int ans = 0;
    function<void(int, int)> dfs2 = [&](int v, int pr) {
        auto old = dp[v];

        recalc_dp(v, -1);
        ans = max(ans, max(dp[v].start_root, dp[v].start_subtree));

        int m = e[v].size();
        vector<dp_forest> suf(m + 2);
        for (int i = m; i >= 1; i--) {
            int to = e[v][i - 1];
            suf[i] = merge(suf[i + 1], dp[to]);
        }

        dp_forest pref;
        for (int i = 1; i <= m; i++) {
            int to = e[v][i - 1];

            if (to != pr) {
                dp[v] = merge(pref, suf[i + 1]).add_root();
                dfs2(to, v);
            }
            pref = merge(pref, dp[to]);
        }
        dp[v] = old;
     };
    dfs2(0, -1);

    return ans;
}

void stress() {
    for (int it = 0;; it++) {
        mt19937 rnd(it);
        db(it);

        int n = rnd() % 50 + 1;
        vector<pair<int, int>> ed;
        for (int i = 1; i < n; i++) {
            ed.push_back({i, rnd() % i});
        }

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        shuffle(p.begin(), p.end(), rnd);

        vector<pair<int, int>> ned;
        for (auto o : ed) {
            ned.push_back({p[o.first], p[o.second]});
        }

        auto get_e = [&](const vector<pair<int, int>> ee) {
            vector<vector<int>> e(n);
            for (auto o : ee) {
                e[o.first].push_back(o.second);
                e[o.second].push_back(o.first);
            }
            return e;
        };

        int ans1 = solve(get_e(ed));
        int ans2 = solve(get_e(ned));
        if (ans1 != ans2) {
            db2(ans1, ans2);
            exit(0);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

//    stress();

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

        printf("%d\n", solve(e));
    }

    return 0;
}