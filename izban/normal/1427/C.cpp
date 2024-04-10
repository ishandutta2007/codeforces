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

int solve(int r, int n, vector<int> t, vector<int> x, vector<int> y) {
    t.insert(t.begin(), 0);
    x.insert(x.begin(), 1);
    y.insert(y.begin(), 1);
    n++;


    vector<int> dp(n, -1);
    vector<int> cmx(n, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i) {
            cmx[i] = max(cmx[i], cmx[i - 1]);
        }
        dp[i] = max(dp[i], cmx[i]);
        if (dp[i] == -1) continue;

        for (int j = 1; j <= 2 * r && i + j < n; j++) {
            if (abs(x[i] - x[i + j]) + abs(y[i] - y[i + j]) <= t[i + j] - t[i]) {
                dp[i + j] = max(dp[i + j], dp[i] + 1);
            }
        }
        if (i + 2 * r < n) {
            cmx[i + 2 * r] = dp[i] + 1;
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int r, n;
    while (scanf("%d%d", &r, &n) == 2) {
        vector<int> t(n), x(n), y(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &t[i], &x[i], &y[i]);
        }

        printf("%d\n", solve(r, n, t, x, y));
    }

    return 0;
}