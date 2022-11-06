#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1 << 20;
using T = int;
inline T combine(T a, T b) {
    return a + b;
}
T DEFAULT = 0;

T a[2 * N];
struct SegmentTreeBottomUp {

    SegmentTreeBottomUp () {
        forn(i, 0, 2 * N)
            a[i] = DEFAULT;
    };

    SegmentTreeBottomUp (vector<T> _a) {
        forn(i, 0, (int)_a.size())
            a[i + N] = _a[i];
        forn(i, (int)_a.size(), N)
            a[i + N] = DEFAULT;
        ford(i, 1, N)
            a[i] = combine(a[2 * i], a[2 * i + 1]);
    }

    T get(int l, int r) {
        T res = DEFAULT;
        l += N, r += N;
        while (l < r) {
            if (l % 2)
                res = combine(a[l++], res);
            if (r % 2)
                res = combine(res, a[--r]);
            l /= 2;
            r /= 2;
        }
        return res;
    }

    void set(int pos, int val) {
        pos += N;
        a[pos] = val;
        pos /= 2;
        while (pos) {
            a[pos] = combine(a[2 * pos], a[2 * pos + 1]);
            pos /= 2;
        }
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    forn(i, 0, n) scanf("%d", &v[i]);
    vector<int> ix(n);
    forn(i, 0, n) ix[i] = i;
    sort(all(ix), [&](int i, int j) {
            return v[i] < v[j];
            });
    SegmentTreeBottomUp t;
    ll ans = 0;
    forn(i, 0, n) {
        t.set(ix[i], 1);
        ans += 1ll * (ix[i] - t.get(0, ix[i])) * t.get(ix[i] + 1, n);
    }
    printf("%lld\n", ans);
}