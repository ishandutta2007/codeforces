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

    int tests;
    scanf("%d", &tests);
    while (tests--) {
        int n, l;
        scanf("%d%d", &n, &l);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        a.insert(a.begin(), 0);
        a.push_back(l);
        n = a.size();

        double L = 0, R = l;
        for (int it = 0; it < 60; it++) {
            double M = (L + R) / 2.0;

            double t1 = M, t2 = M;
            double x1 = l, x2 = 0;
            for (int i = 0; i < n - 1; i++) {
                double need = 1.0 * (a[i + 1] - a[i]) / (i + 1);
                if (need <= t1) t1 -= need;
                else {
                    x1 = a[i] + t1 * (i + 1);
                    break;
                }
            }

            for (int i = n - 1; i > 0; i--) {
                double need = 1.0 * (a[i] - a[i - 1]) / (n - i);
                if (need <= t2) t2 -= need;
                else {
                    x2 = a[i] - t2 * (n - i);
                    break;
                }
            }

            if (x1 <= x2) L = M;
            else R = M;
        }
        printf("%.17f\n", R);
    }

    return 0;
}