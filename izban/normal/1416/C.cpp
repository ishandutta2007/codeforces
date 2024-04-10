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

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        const int K = 30;
        vector<vector<ll>> cost(K, vector<ll>(2));

        vector<vector<int>> nxt(1, vector<int>(2, -1));
        vector<int> cnt(1, 0);

        for (int i = 0; i < n; i++) {
            int x = a[i];
            int cur = 0;
            for (int j = K - 1; j >= 0; j--) {
                int cbit = (x >> j) & 1;

                if (nxt[cur][cbit] == -1) {
                    nxt[cur][cbit] = nxt.size();
                    nxt.push_back(vector<int>(2, -1));
                    cnt.push_back(0);
                }
                cost[j][cbit] += nxt[cur][cbit ^ 1] == -1 ? 0 : cnt[nxt[cur][cbit ^ 1]];
                cnt[cur]++;
                cur = nxt[cur][cbit];
            }
            cnt[cur]++;
        }

        ll ans = 0;
        int ansv = 0;
        for (int j = K - 1; j >= 0; j--) {
            ans += min(cost[j][0], cost[j][1]);
            if (cost[j][0] > cost[j][1]) {
                ansv += 1 << j;
            }
        }
        printf("%lld %d\n", ans, ansv);
    }

    return 0;
}