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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        vector<vector<pair<int, int>>> e(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            e[u].push_back({w, v});
        }

        vector<vector<int>> vct(k + 1);
        for (int i = 0; i < n; i++) {
            sort(e[i].begin(), e[i].end());
            assert((int)e[i].size() <= k);
            vct[e[i].size()].push_back(i);
        }

        vector<vector<vector<vector<int>>>> can(k + 1,
                vector<vector<vector<int>>>(k + 1,
                        vector<vector<int>>(k + 1,
                                vector<int>(k + 1, 1))));

        vector<int> banned(k + 1);

        for (int i = 0; i <= k; i++) {
            vector<int> mask(n);
            for (int v : vct[i]) {
                assert(e[v].size() == i);
                for (int j = 0; j < i; j++) {
                    int to = e[v][j].second;
                    if (mask[to] & (1 << j)) {
                        banned[i] |= 1 << j;
                    }
                    mask[to] |= 1 << j;
                }
            }

            bool ok = 1;
            for (int j = i + 1; j <= k; j++) {
                for (int t = 0; t < j; t++) {
                    int cbanned = 0;
                    for (int v : vct[j]) {
                        int to = e[v][t].second;
                        cbanned |= mask[to];
                    }
                    for (int l = 0; l <= k; l++) if (cbanned & (1 << l)) {
//                        cerr << i << " " << l << " " << j << " " << t << endl;
                        can[i][l][j][t] = 0;
                    }
                }
            }
        }
//        return 0;

        int ans = 0;
        vector<int> p;
        function<void(int)> rec = [&](int cur) {
            if (cur == k) {
                ans++;
//                dbv(p);
                return;
            }
            for (int val = 0; val <= cur; val++) {
                p.push_back(val);

                bool ok = 1;
                for (int j = 0; j < cur; j++) {
                    ok &= can[j + 1][p[j]][cur + 1][val];
                }
                ok &= (banned[cur + 1] & (1 << val)) == 0;
                if (ok) {
                    rec(cur + 1);
                }

                p.pop_back();
            }
        };
        rec(0);
//        return 0;

        printf("%d\n", ans);
    }

    return 0;
}