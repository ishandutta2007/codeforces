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

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &b[i]);

        vector<vector<int>> c(n);
        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            c[i].resize(k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &c[i][j]);
                c[i][j]--;
            }
        }

        struct ed {
            int u, v, w;
            bool operator< (const ed &e) const {
                return w > e.w;
            }
        };
        long long sum = 0;
        vector<ed> edges;
        for (int i = 0; i < n; i++) {
            for (int x : c[i]) {
                edges.push_back({i, n + x, a[i] + b[x]});
                sum += edges.back().w;
            }
        }
        sort(edges.begin(), edges.end());
        struct dsu {
            int n;
            vector<int> p;
            dsu(int _n) {
                n = _n;
                p.resize(n);
                iota(p.begin(), p.end(), 0);
            }
            int get(int x) {
                return x == p[x] ? x : p[x] = get(p[x]);
            }
            bool uni(int u, int v) {
                u = get(u);
                v = get(v);
                if (u == v) return 0;
                p[v] = u;
                return 1;
            }
        };
        dsu d(n + m);
        for (auto o : edges) {
            if (d.uni(o.u, o.v)) {
                sum -= o.w;
            }
        }
        printf("%lld\n", sum);
    }

    return 0;
}