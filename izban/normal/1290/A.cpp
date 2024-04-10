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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);


        vector<int> b;
        int left = n - m;
        for (int i = 0; i + left < n; i++) {
            b.push_back(max(a[i], a[i + left]));
        }

        int t = b.size();
        vector<vector<int>> mn(t, vector<int>(t));
        for (int i = 0; i < t; i++) {
            int cur = b[i];
            for (int j = i; j < t; j++) {
                cur = min(cur, b[j]);
                mn[i][j] = cur;
            }
        }

        k = min(k, m - 1);
        assert(k < t);

        int ans = -1;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; i + j <= k; j++) {
                ans = max(ans, mn[i][t - 1 - j]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}