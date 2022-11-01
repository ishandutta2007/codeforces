#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 500500;

int n, q;
int a[maxn], b[maxn];
int cnt[maxn];

i64 res = 0;

vi primes(int n) {
    vi res;
    if (n%2 == 0) res.pb(2);
    while (n%2 == 0) n /= 2;

    for (int i = 3; i*i <= n; i += 2) {
        if (n % i == 0) {
            res.pb(i);
            while (n%i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) {
        res.pb(n);
    }

    return res;
}

void scan() {
    scanf("%d%d", &n, &q);
    forn(i, n) {
        scanf("%d", &a[i]);
    }
}

void solve() {
    forn(i, q) {
        int p;
        scanf("%d", &p); --p;

        vi pr = primes(a[p]);
        vi ra, rb;
        forn(m, 1<<(pr.size())) {
            int t = 1;
            forn(j, pr.size()) if (m&(1<<j)) t *= pr[j];
            if (__builtin_popcount(m) % 2) ra.pb(t);
            else rb.pb(t);
        }


        if (b[p]) {
            for (auto x: ra) --cnt[x];
            for (auto x: rb) --cnt[x];
        }

        for (auto x: ra) res += cnt[x] * (b[p] ? 1 : -1);
        for (auto x: rb) res -= cnt[x] * (b[p] ? 1 : -1);

        if (!b[p]) {
            for (auto x: ra) ++cnt[x];
            for (auto x: rb) ++cnt[x];
        }

        b[p] = !b[p];

        printf("%I64d\n", res);
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}