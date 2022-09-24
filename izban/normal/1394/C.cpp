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

const int INF = (int)1.01e9;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            static char buf[(int)1.01e6];
            scanf("%s", buf);
            int cn = 0, cb =0;

            string s(buf);
            for (char c : s) {
                if (c == 'B') cb++;
                else if (c == 'N') cn++;
                else assert(0);
            }
            a.emplace_back(cn, cb);
        }

        pair<int, int> sert;
        auto check = [&](int M) {
            vector<int> mn(3, INF);
            vector<int> mx(3, -INF);
            mx[0] = mx[1] = 0;
            for (auto p : a) {
                mn[0] = min(mn[0], p.first + M);
                mn[1] = min(mn[1], p.second + M);
                mn[2] = min(mn[2], p.first - p.second + M);

                mx[0] = max(mx[0], p.first - M);
                mx[1] = max(mx[1], p.second - M);
                mx[2] = max(mx[2], p.first - p.second - M);
            }

            bool ok = 1;
            for (int i = 0; i < 3; i++) {
                ok &= mx[i] <= mn[i];
            }

            if (ok) {
                int x = INF, y = INF;
                for (int xx = mx[0]; xx <= mn[0]; xx++) {
                    // mx[2] <= x-y <= mn[2]
                    // mx[2]-x <= -y <= mn[2]-x
                    // x-mn[2] <= y <= x-mx[2]
                    int l1 = xx-mn[2];
                    int r1 = xx-mx[2];

                    int l2 = mx[1];
                    int r2 = mn[1];

                    if (min(r1, r2) - max(l1, l2) >= 0) {
                        if (xx > 0 || min(r1, r2) > 0) {
                            x = xx;
                            y = min(r1, r2);
                            break;
                        }
                    }
                }
                if (x == INF) {
                    ok = 0;
                    return ok;
                }

                assert(x != INF);

                sert = {x, y};

                assert(mx[0] <= x && x <= mn[0]);
                assert(mx[1] <= y && y <= mn[1]);
                assert(mx[2] <= x-y && x-y <= mn[2]);
            }
            return ok;
        };

        int L = -1, R = 1e6;
        while (R - L > 1) {
            int M = (L + R) >> 1;

            if (check(M)) R = M;
            else L = M;
        }
        auto checked = check(R);
        assert(checked);

        string res = string(sert.first, 'N') + string(sert.second, 'B');

        printf("%d\n%s\n", R, res.c_str());
//        db2(sert.first, sert.second);
//        for (auto o : a) {
//            db2(o.first, o.second);
//        }
    }

    return 0;
}