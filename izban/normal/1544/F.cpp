//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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
const int MOD = 31607;
//const int MOD = 10007;
const int DENOM = 1e4;


int mul(int a, int b) {
    return a * b % MOD;
}

void add(int &a, int b) {
//    a = (a + b) % MOD;
    a += b;
    if (a >= MOD) a -= MOD;
}

int bin(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

int inv(int x) {
    return bin(x, MOD - 2);
}

int slow(vector<vector<int>> a) {
    int n = a.size();

    // 1 -- was zero or not

    int MASKS = 1 << (n + 3);
    int D1 = 1 << n;
    int D2 = 1 << (n + 1);
    int ROW = 1 << (n + 2);

    vector<int> cdp(1 << (n + 3));
    cdp[ROW] = 1;

    for (int i = 0; i < n; i++) {
        dbv(cdp);
        for (int mask = 0; mask < ROW; mask++) {
            cdp[mask] = cdp[mask + ROW];
            cdp[mask + ROW] = 0;
        }
        for (int j = 0; j < n; j++) {
            int or_mask_zero = 0;
            or_mask_zero |= 1 << j;
            if (i == j) or_mask_zero |= D1;
            if (i + j == n - 1) or_mask_zero |= D2;
            or_mask_zero |= ROW;

            int coef_1 = mul(a[i][j], inv(DENOM));
            int coef_0 = (1 - coef_1 + MOD) % MOD;

            for (int mask = MASKS - 1; mask >= 0; mask--) {
                int prod = mul(cdp[mask], coef_0);
                add(cdp[mask], MOD - prod);
                add(cdp[mask | or_mask_zero], prod);
            }
        }
    }
    dbv(cdp);

    int ans = cdp[MASKS - 1];
    ans = (1 - ans + MOD) % MOD;
    return ans;
}

int solve(vector<vector<int>> a) {
//    return slow(a);
    int n = a.size();

    // 1 -- was zero or not

    int ans = 0;
    int m = min(n - 1, 5);
//    int m = 0;

    int D1 = 1 << n;
    int D2 = 1 << (n + 1);
    int IDENOM = inv(DENOM);

    vector<vector<int>> prob_zero(n, vector<int>(n));
    vector<vector<int>> prob_one(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prob_zero[i][j] = (1 - mul(a[i][j], inv(DENOM)) + MOD) % MOD;
            prob_one[i][j] = (mul(a[i][j], inv(DENOM)) + MOD) % MOD;
        }
    }

    for (int fmask = 0; fmask < (1 << (n + 2 - m)); fmask++) {
        int fixed = fmask << m;

        int MASKS = 1 << (m + 1);
        int ROW = 1 << m;
        vector<int> cdp(MASKS);
        cdp[ROW] = 1;
        for (int i = 0; i < n; i++) {
//            dbv(cdp);
            for (int mask = 0; mask < ROW; mask++) {
                cdp[mask] = cdp[mask + ROW];
                cdp[mask + ROW] = 0;
            }
            for (int j = 0; j < m; j++) {
                if ((fixed & D1) && (i == j)) continue;
                if ((fixed & D2) && (i + j == n - 1)) continue;

                int or_mask_zero = (1 << j) | ROW;
                int coef_0 = prob_zero[i][j];

                for (int mask = MASKS - 1; mask >= 0; mask--) {
                    int prod = mul(cdp[mask], coef_0);
                    add(cdp[mask], MOD - prod);
                    add(cdp[mask | or_mask_zero], prod);
                }
            }
            int coef_1 = 1;
            for (int j = m; j < n; j++) {
                int x = prob_one[i][j];
                if ((fixed & D1) && (i == j)) x = 1;
                if ((fixed & D2) && (i + j == n - 1)) x = 1;
                if ((fixed & (1 << j))) x = 1;

                coef_1 = mul(coef_1, x);
            }
            int coef_0 = (1 - coef_1 + MOD) % MOD;
            /*int coef_0 = 0, coef_1 = 1;
            for (int j = m; j < n; j++) {
                int nc0 = 0, nc1 = 0;
                int x = 0;
                if ((fixed & D1) && (i == j)) x = 1;
                if ((fixed & D2) && (i + j == n - 1)) x = 1;
                if ((fixed & (1 << j))) x = 1;
                if (x) {
                    nc0 = coef_0;
                    nc1 = mul(coef_1, prob_one[i][j]);
                } else {
                    nc0 = coef_0 + mul(nc1, prob_zero[i][j]);
                    nc1 = mul(coef_1, prob_one[i][j]);
                }
                coef_0 = nc0;
                coef_1 = nc1;
            }*/

            int or_mask_zero = ROW;

            for (int mask = MASKS - 1; mask >= 0; mask--) {
                int prod = mul(cdp[mask], coef_0);
                add(cdp[mask], MOD - prod);
                add(cdp[mask | or_mask_zero], prod);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int t = 0;
                if ((fixed & D1) && (i == j)) t = 1;
                if ((fixed & D2) && (i + j == n - 1)) t = 1;
                if ((fixed & (1 << j))) t = 1;
                if (t) cdp[MASKS - 1] = mul(cdp[MASKS - 1], prob_one[i][j]);
            }
        }
//        dbv(cdp);
        int cur_all_zeroes = cdp[MASKS - 1];
        int cur_any_row_one = (1 - cur_all_zeroes+ MOD) % MOD;

        int coef = 1;
        if (__builtin_popcount(fmask) % 2 == 1) coef = MOD - 1;

//        db(cur_any_row_one);

        add(ans, mul(cur_all_zeroes, coef));
    }

    ans = (1 - ans + MOD) % MOD;
    return ans;
}

void test() {
    mt19937 rnd;
    int n = 20;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rnd() % (DENOM + 1);
        }
    }
    int res = solve(a);
    cout << res << endl;
//    exit(0);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
//    test();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        printf("%d\n", solve(a));
    }

    return 0;
}