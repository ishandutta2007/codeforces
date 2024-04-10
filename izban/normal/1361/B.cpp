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

const int MOD = (int)1e9 + 7;

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

void add(int &a, int b) {
    a = (a + b) % MOD;
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

int solve(int n, int p, vector<int> a) {
    if (p == 1) {
        if (n % 2 == 0) return 0;
        return 1;
    }

    int m = *max_element(a.begin(), a.end()) + 1;
    vector<int> b(m);
    for (int i = 0; i < n; i++) b[a[i]]++;

    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        c[i] += b[i];
        if (i < m - 1) {
            c[i + 1] += c[i] / p;
        }
    }

    ll bigger = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (bigger > 0) {
            if (bigger > c[i]) {
                int ans = bigger % MOD;
                for (int j = i; j >= 0; j--) {
                    add(ans, MOD - b[j]);
                    if (j > 0) {
                        ans = mul(ans, p);
                    }
                }
                return ans;
            }
            ll k = min(bigger, (ll)b[i]);
            bigger -= k;
            b[i] -= k;
        }
        b[i] %= 2;
        bigger += b[i];
        if (i > 0) {
            bigger *= p;
        }
    }
    return bigger % MOD;
}

int solve2(int n, int p, vector<int> a) {
    if (p == 1) {
        if (n % 2 == 0) return 0;
        return 1;
    }

    sort(a.begin(), a.end());
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            int x = c[i] + 1;
            for (int j = 0; j < a[i + 1] - a[i] && x > 0; j++) {
                x /= p;
            }
            c[i + 1] += x;
        }
    }

    ll x = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (x == 0) x = 1;
        else x--;

        if (x > c[i]) {
            for (int j = i; j >= 0; j--) {
                if (j != i) {
                    x = (x - 1 + MOD) % MOD;
                }
                int dif = a[j] - (j > 0 ? a[j - 1] : 0);
                x = mul(x, bin(p, dif));
            }
            return x % MOD;
        }
        int dif = a[i] - (i > 0 ? a[i - 1] : 0);
        x = mul(x, bin(p, dif));
    }
    return x;

}

void stress() {
    for (int it = 0; ; it++) {
        mt19937 rnd(it);
        db(it);

        int n = rnd() % 10 + 1;
        int p = rnd() % 10 + 1;
        int c = rnd() % 5 + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = rnd() % c;
        db2(n, p);
        dbv(a);
        auto ans1 = solve(n, p, a);
        auto ans2 = solve2(n, p, a);
        if (ans1 != ans2) {
            db2(ans1, ans2);
            exit(0);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
//    stress();

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, p;
        scanf("%d%d", &n, &p);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        printf("%d\n", solve2(n, p, a));
    }

    return 0;
}