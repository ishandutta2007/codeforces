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
        vector<pair<int, int>> a(n), b(m);
        for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
        for (int i = 0; i < m; i++) scanf("%d%d", &b[i].first, &b[i].second);

        int C = 0;
        for (auto o : a) {
            C = max(C, o.first);
            C = max(C, o.second);
        }
        for (auto o : b) {
            C = max(C, o.first);
            C = max(C, o.second);
        }

        C += 5;
        vector<int> vct(C);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int dx = b[j].first - a[i].first;
                int dy = b[j].second - a[i].second;
                if (dx >= 0 && dy >= 0) {
                    vct[dx] = max(vct[dx], dy + 1);
                }
            }
        }

        int ans = 1e9;
        int cmx = 0;
        for (int dx = C - 1; dx >= 0; dx--) {
            cmx = max(cmx, vct[dx]);
            ans = min(ans, dx + cmx);
        }
        printf("%d\n", ans);
    }

    return 0;
}