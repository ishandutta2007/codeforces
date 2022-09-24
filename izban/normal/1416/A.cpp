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

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i =0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        vector<vector<int>> vct(n);
        for (int i = 0; i < n; i++) {
            vct[i].push_back(-1);
        }
        for (int i = 0; i < n; i++) {
            vct[a[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            vct[i].push_back(n);
        }

        const int INF = 1e9;
        vector<int> ans(n, INF);
        for (int i = 0; i < n; i++) {
            int mx = -1;
            for (int j = 1; j < (int)vct[i].size(); j++) {
                mx = max(mx, vct[i][j] - vct[i][j - 1]);
            }
            if (mx <= n) {
                ans[mx - 1] = min(ans[mx - 1], i);
            }
        }
        for (int i = 1; i < n; i++) ans[i] = min(ans[i], ans[i - 1]);
        for (int i = 0; i < n; i++) {
            if (ans[i] == INF) ans[i] = -1;
            else ans[i]++;
        }

        for (int i =0 ; i < n; i++) printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }

    return 0;
}