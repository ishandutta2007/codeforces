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
#include <chrono>

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

#ifdef LOCAL
const double TL = 0.2;
#else
const double TL = 2.0;
#endif


ll solve(vector<ll> a) {
    double start = clock() / (double)CLOCKS_PER_SEC;

    const int N = 1.001e6;
    vector<int> ispr(N, 1);
    vector<int> pr;
    for (int i = 2; i < N; i++) {
        if (ispr[i]) {
            pr.push_back(i);
            for (int j = i + i; j < N; j += i) {
                ispr[j] = 0;
            }
        }
    }

    auto fact = [&](ll x) {
        vector<ll> res;
        for (ll p : pr) {
            if (x % p == 0) {
                while (x % p == 0) x /= p;
                res.push_back(p);
            }
        }
        if (x > 1) res.push_back(x);
        return res;
    };

    ll ans = 1e18;
    auto solve = [&](ll x) {
        if (x == 0) return;
        auto cur = fact(x);

        for (ll p : cur) {
            ll res = 0;
            for (ll z : a) {
                ll t = p - z % p;
                if (z >= p) t = min(t, z % p);
                res += t;
            }
            ans = min(ans, res);
        }
    };

    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    int n = a.size();
    while (clock() / (double)CLOCKS_PER_SEC - start < TL) {
        int id = rnd() % n;

        solve(a[id]);
        solve(a[id] - 1);
        solve(a[id] + 1);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        printf("%lld\n", solve(a));
    }

    return 0;
}