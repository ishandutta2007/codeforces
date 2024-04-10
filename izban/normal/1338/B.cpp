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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

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

        vector<int> leaf(n);
        for (int i = 0; i < n; i++) leaf[i] = e[i].size() == 1;

        vector<int> d(n, -1);
        function<void(int, int)> dfs = [&](int v, int c) {
            if (d[v] != -1) return;
            d[v] = c;
            for (int to : e[v]) {
                dfs(to, c ^ 1);
            }
        };
        dfs(0, 0);

        vector<int> cc;
        for (int i = 0; i < n; i++) {
            if (leaf[i]) {
                cc.push_back(d[i]);
            }
        }
        sort(cc.begin(), cc.end());

        int mn = cc[0] == cc.back() ? 1 : 3;

        int mx = n - 1;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int to : e[i]) {
                if (leaf[to]) cur++;
            }
            mx -= max(0, cur - 1);
        }

        printf("%d %d\n", mn, mx);
    }

    return 0;
}