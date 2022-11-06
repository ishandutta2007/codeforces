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
int cnt[N];

ll Pow(ll a, ll b) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) x = x * y % MOD;
        y = y * y % MOD;
        b /= 2;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    forn(i, 0, 20)
        forn(j, 0, N)
        if ((j & (1 << i)) == 0) {
            cnt[j] += cnt[j | (1 << i)];
        }
    ll ans = 0;
    forn(i, 0, N) {
        int sz = __builtin_popcount(i);
        ll P = Pow(2, cnt[i]);
        if (sz % 2) {
            ans -= P;
            if (ans < 0) ans += MOD;
        } else {
            ans += P;
            if (ans >= MOD) ans -= MOD;
        }
    }
    cout << ans << '\n';
}