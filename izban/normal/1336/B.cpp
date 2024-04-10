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

    int T;
    scanf("%d", &T);
    while (T--) {
        vector<int> n(3);
        for (int i = 0; i < 3; i++) scanf("%d", &n[i]);

        vector<vector<int>> a(3);
        for (int i = 0; i < 3; i++) {
            a[i].resize(n[i]);
            for (int j = 0; j < n[i]; j++) {
                scanf("%d", &a[i][j]);
            }
            sort(a[i].begin(), a[i].end());
        }

        ll ans = 4e18;
        for (int md = 0; md < 3; md++) {
            for (int mn = 0; mn < 3; mn++) {
                if (mn == md) continue;
                int mx = 0 + 1 + 2 - md - mn;


                int j = -1, k = 0;
                for (int i = 0; i < n[md]; i++) {
                    while (j + 1 < n[mn] && a[mn][j + 1] <= a[md][i]) j++;
                    while (k < n[mx] && a[mx][k] < a[md][i]) k++;

                    if (j >= 0 && k < n[mx]) {
                        ll x = a[mn][j];
                        ll y = a[md][i];
                        ll z = a[mx][k];
                        ll cans = (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z);
                        ans = min(ans, cans);
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}