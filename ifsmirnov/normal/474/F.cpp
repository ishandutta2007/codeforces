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
const int sz = 1<<17;
const int maxn = 100500;

i64 gcd(i64 x, i64 y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

int relax(i64 x, i64 y) {
    return gcd(x, y);
//     if (x == 0) return y;
//     if (y == 0) return x;
//     i64 t = x * y / gcd(x, y);
//     return min(t, (i64)inf);
}

pii relax(const pii& a, const pii& b) {
    if (a.fi < b.fi) return a;
    if (b.fi < a.fi) return b;
    return mp(a.fi, a.se+b.se);
}

pii rmq[sz*2];
pii getr(int l, int r) {
    l += sz;
    r += sz;
    pii mx = mp(inf, -1);
    while (l < r) {
        if (l%2 == 1) mx = relax(mx, rmq[l]);
        if (r%2 == 0) mx = relax(mx, rmq[r]);
        l = (l+1)/2;
        r = (r-1)/2;
    }
    if (l == r) mx = relax(mx, rmq[l]);
    return mx;
}
void updr(int i, int x) {
    i += sz;
    rmq[i] = mp(x, 1);
    for (i /= 2; i; i /= 2) {
        rmq[i] = relax(rmq[i*2], rmq[i*2+1]);
    }
}

int lcm[sz*2];
int getl(int l, int r) {
    l += sz;
    r += sz;
    int mx = 0;
    while (l < r) {
        if (l%2 == 1) mx = relax(mx, lcm[l]);
        if (r%2 == 0) mx = relax(mx, lcm[r]);
        l = (l+1)/2;
        r = (r-1)/2;
    }
    if (l == r) mx = relax(mx, lcm[l]);
    return mx;
}
void updl(int i, int x) {
    i += sz;
    lcm[i] = x;
    for (i /= 2; i; i /= 2) {
        lcm[i] = relax(lcm[i*2], lcm[i*2+1]);
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    forn(i, sz-1) updr(i, inf);

    int n;
    scanf("%d", &n);
    forn(i, n) {
        int x;
        scanf("%d", &x);
        updr(i, x);
        updl(i, x);
    }
    int q;
    scanf("%d", &q);
    forn(i, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;--r;
        pii mx = getr(l, r);
        int lc = getl(l, r);
        if (lc % mx.fi == 0) {
            printf("%d\n", r-l+1-mx.se);
        } else {
            printf("%d\n", r-l+1);
        }
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}