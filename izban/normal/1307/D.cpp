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
const int INF = 1e9;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        vector<vector<int>> e(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }


        auto bfs = [&](int s) {
            vector<int> d(n, INF);
            vector<int> q;
            q.push_back(s);
            d[s] = 0;
            for (int i = 0; i < (int)q.size(); i++) {
                int v = q[i];
                for (int to : e[v]) {
                    if (d[to] > d[v] + 1) {
                        d[to] = d[v] + 1;
                        q.push_back(to);
                    }
                }
            }
            return d;
        };

        auto d1 = bfs(0);
        auto d2 = bfs(n - 1);

        vector<vector<int>> vct(n);

        for (int v : a) {
            vct[d1[v]].push_back(v);
        }


        vector<int> mx(n + 1);
        mx[n] = -INF;
        for (int i = n - 1; i >= 0; i--) {
            mx[i] = mx[i + 1];
            for (int v : vct[i]) {
                mx[i] = max(mx[i], d2[v]);
            }
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (vct[i].size() > 1) {
                ans = max(ans, d1[n - 1]);
            }
            if (vct[i].size() > 0) {
                ans = max(ans, min(d1[n - 1], i + 1 + mx[i + 1]));
            }
        }
        assert(ans <= d1[n - 1]);
        cout << ans << endl;
    }

    return 0;
}