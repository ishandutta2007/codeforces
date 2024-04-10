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

struct dsu {
    int n;
    vector<int> p;
    vector<int> edge_col;
    vector<int> col;
    vector<int> diff;
    vector<int> sz;

    int sum = 0;

    dsu(int _n) {
        n = _n;
        p.resize(n);
        edge_col.assign(n, 0);
        col.assign(n, -1);
        diff.assign(n, 0);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++) p[i] = i;
    }

    int get(int x) {
        if (x == p[x]) {
            return x;
        }
        int pr = p[x];
        p[x] = get(pr);
        edge_col[x] ^= edge_col[pr];
        return p[x];
    }

    auto recalc_sum(int v, int delta) {
        if (col[v] == -1) {
            sum += min(diff[v], sz[v] - diff[v]) * delta;
        } else {
            sum += (col[v] == 0 ? diff[v] : sz[v] - diff[v]) * delta;
        }
    }

    void set(int u, int new_col) {
        int pu = get(u);
        if (col[pu] == -1) {
            recalc_sum(pu, -1);
            col[pu] = edge_col[u] ^ new_col;
            recalc_sum(pu, +1);
        } else {
            assert((col[pu] ^ edge_col[u] ^ new_col) == 0);
        }
    }

    void uni(int u, int v, int ed) {
        int pu = get(u);
        int pv = get(v);
        if (pu == pv) {
            assert((edge_col[u] ^ edge_col[v] ^ ed) == 0);
            return;
        }
        if (sz[pu] < sz[pv]) {
            swap(pu, pv);
            swap(u, v);
        }

        recalc_sum(pu, -1);
        recalc_sum(pv, -1);

        int root_edge = edge_col[u] ^ edge_col[v] ^ ed;

        if (col[pu] != -1 && col[pv] != -1) {
            assert((col[pu] ^ col[pv] ^ root_edge) == 0);
        } else if (col[pv] != -1) {
            col[pu] = col[pv] ^ root_edge;
        }

        p[pv] = pu;
        sz[pu] += sz[pv];
        if (root_edge == 0) diff[pu] += diff[pv];
        else diff[pu] += sz[pv] - diff[pv];
        edge_col[pv] = root_edge;

        recalc_sum(pu, +1);
    }
};

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, k;
    bool first = 1;
    while (scanf("%d%d", &n, &k) == 2) {
        if (first) first = 0;
        else printf("\n");

        static char buf[(int)1.01e6];
        scanf("%s", buf);
        string s = buf;
        vector<vector<int>> a(k);
        for (int i = 0; i < k; i++) {
            int m;
            scanf("%d", &m);
            a[i].resize(m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                a[i][j]--;
            }
        }

        vector<vector<int>> vct(n);
        for (int i = 0; i < k; i++) {
            for (int x : a[i]) {
                vct[x].push_back(i);
            }
        }

        dsu d(k);
        for (int i = 0; i < n; i++) {
            if (vct[i].empty()) {
                assert(s[i] == '1');
            } else {
                if (vct[i].size() == 1) {
                    d.set(vct[i][0], (s[i] == '1' ? 0 : 1));
                } else {
                    assert(vct[i].size() == 2);
                    d.uni(vct[i][0], vct[i][1], (s[i] == '1') ? 0 : 1);
                }
            }
            printf("%d\n", d.sum);
        }
    }

    return 0;
}