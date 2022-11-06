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

const int K = 6;

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    forn(i, 0, n) scanf("%lld", &a[i]);
    vector<char> imp(n);
    forn(i, 0, n) {
        if (i == 0 || i == n - 1) {
            imp[i] = 1;
            continue;
        }
        if (a[i] >= a[i - 1] && a[i] >= a[i + 1] ||
                a[i] <= a[i - 1] && a[i] <= a[i + 1]) {
            imp[i] = imp[i - 1] = imp[i + 1] = 1;
        }
    }
    vector<pair<ll, int>> prev(K, {0, -1});
    int it = 0;
    forn(i, 0, n) if (imp[i]) {
        ll opt = 0;
        for (auto p : prev) {
            opt = max(opt, p.fs + abs(a[i] - a[p.sn + 1]));
        }
        prev[it] = {opt, i};
        ++it;
        if (it == K) it = 0;
    }
    ll ans = 0;
    for (auto p : prev) ans = max(ans, p.fs);
    printf("%lld\n", ans);
}