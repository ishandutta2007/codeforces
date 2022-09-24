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

void solve(int L, int R) {
    const int INF = 1e9;
    static int n = 1e6;
    static int calculated = 0;
    static vector<int> dp, pr;
    if (!calculated) {
        calculated = 1;
        dp.assign(n + 1, INF);
        pr.assign(n + 1, -1);

        dp[1] = 2;
        dp[0] = 10;
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= 3; j++) {
                int cur;
                if (j == 2) cur = dp[i / 2] + 1 + (i % j);
                if (j == 3) cur = dp[i / 3] + 2 + max(0, i % j - 1);
                if (dp[i] > cur) {
                    dp[i] = cur;
                    pr[i] = j;
                }
            }
        }

        if (0) {
            int j = max_element(dp.begin(), dp.end()) - dp.begin();
            cerr << j << " " << dp[j] << endl;
            return;
        }
    }


    function<vector<vector<pair<int, int>>>(int)> rec = [&](int i) {
        if (i == 1) {
            vector<vector<pair<int, int>>> e(2);
            e[1].push_back({0, 1});
            return e;
        }

        int j = pr[i];
        int each = i / j;
        auto e = rec(each);

        int prv = e.size() - 1;

        if (j == 2) {
            int tmp = -1;
            if (i % j) {
                tmp = e.size();
                e.emplace_back();
            }
            int last = e.size();
            e.emplace_back();
            for (auto ed : e[prv]) {
                e[last].emplace_back(ed.first, ed.second);
            }
            e[last].emplace_back(prv, each);
            if (tmp != -1) {
                e[last].emplace_back(tmp, 1);
                e[tmp].emplace_back(0, 2 * each);
            }
            return e;
        }

        if (j == 3) {
            int tmp = -1;
            if (i % j == 2) {
                tmp = e.size();
                e.emplace_back();
            }
            int buf = e.size();
            e.emplace_back();

            int last = e.size();
            e.emplace_back();
            for (auto ed : e[prv]) {
                e[last].emplace_back(ed.first, ed.second);
            }
            e[last].emplace_back(prv, each);

            e[last].emplace_back(buf, each);
            e[buf].emplace_back(prv, each);

            if (i % j >= 1) {
                e[buf].emplace_back(0, 2 * each + 1);
            }

            if (tmp != -1) {
                e[last].emplace_back(tmp, 1);
                e[tmp].emplace_back(0, i - 1);
            }
            return e;
        }
        assert(0);
    };

    auto e = rec(R - L + 1);
    vector<pair<int, pair<int, int>>> ed;
    int k = e.size();
    for (int i = 0; i < k; i++) {
        for (auto cur : e[i]) {
            int real_w = cur.second;
            if (cur.first == 0) real_w += L - 1;
            ed.emplace_back(k - i, make_pair(k - cur.first, real_w));
        }
    }
    assert(k <= 32);

    if (1) {
        cout << "YES" << endl;
        cout << e.size() << " " << ed.size() << endl;
        for (auto o : ed) {
            cout << o.first << " " << o.second.first << " " << o.second.second << endl;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif


    if (0) {
        for (int i = 1; i <= 1e6; i++) {
            if (i % 1000 == 0) {
                cerr << i << endl;
                solve(1, i);
            }
        }
    }

    int L, R;
    while (cin >> L >> R) {
        solve(L, R);
    }


    return 0;
}