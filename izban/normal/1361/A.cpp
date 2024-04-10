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
        vector<vector<int>> e(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i]);
            t[i]--;
        }

        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = i;
        sort(a.begin(), a.end(), [&](int i, int j) {
            return t[i] < t[j];
        });

        bool ok = 1;
        for (int v = 0; v < n; v++) {
            vector<int> vct;
            for (int to : e[v]) {
                vct.push_back(t[to]);
            }
            sort(vct.begin(), vct.end());
            vct.resize(unique(vct.begin(), vct.end()) - vct.begin());

            int x = 0;
            while (x < (int)vct.size() && vct[x] == x) {
                x++;
            }
            ok &= x == t[v];
        }

        if (ok) for (int i = 0; i < n; i++) printf("%d%c", a[i] + 1, " \n"[i + 1 == n]);
        else printf("-1\n");
    }

    return 0;
}