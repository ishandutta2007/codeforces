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

const int K = 1 << 10;

int a[K], b[K];

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    forn(i, 0, n) {
        int t;
        scanf("%d", &t);
        ++a[t];
    }
    while (k--) {
        int r = 0;
        forn(i, 0, K) {
            b[i] += (a[i] + r) / 2;
            b[i ^ x] += (a[i] + 1 - r) / 2;
            r = (r + a[i]) % 2;
        }
        memcpy(a, b, sizeof a);
        memset(b, 0, sizeof b);
    }
    int mn = INF, mx = 0;
    forn(i, 0, K) {
        if (a[i]) {
            mn = min(i, mn);
            mx = max(i, mx);
        }
    }
    printf("%d %d\n", mx, mn);
}