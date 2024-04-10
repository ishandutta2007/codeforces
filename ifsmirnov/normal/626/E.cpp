#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
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
typedef long double ld;
const int maxn = 200500;

int n;
int a[maxn];
i64 s[maxn];

ld best;
int bm, blen;

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);

    sort(a, a+n);
    forn(i, n) {
        s[i] = a[i];
        if (i) s[i] += s[i-1];
    }
}

i64 get(int l, int r) {
    return s[l] - (r ? s[r-1] : 0);
}

ld eval(int m, int len) {
    if (len == 0) {
        return 0;
    }
    assert(m >= len);
    assert(n-len > m);
    i64 sum = get(n-1, n-len) + get(m-1, m-len) + a[m];
    return (ld)sum / (len * 2 + 1);
}

void relax(int m, int len) {
    ld med = a[m];
    ld t = eval(m, len) - med;
    if (t > best) {
        best = t;
        bm = m;
        blen = len;
    }
}

void solve() {
    relax(0, 0);
    forn(m, n) {
        int l = 0;
        int r = min(m, n - m - 1);

        relax(m, r);

        // max l: f(l+1) > f(r)
        while (r-l > 1) {
            int mid = (r+l) / 2;
            if (eval(m, mid+1) > eval(m, mid)) l = mid;
            else r = mid;
        }

        relax(m, l);
        relax(m, r);
    }

//     fprintf(stderr, "%.10lf\n", (double)best);
    vi res;
    res.pb(a[bm]);
    forn(i, blen) {
        res.pb(a[n-i-1]);
        res.pb(a[bm-i-1]);
    }
    sort(all(res));
    printf("%d\n", (int)res.size());
    for (auto x: res) printf("%d ", x);
    printf("\n");
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