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

const int N = 2017;
ll dp[N][N];
ll sum[N][N];

ll Add(ll x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    forn(i, 0, N) dp[0][i] = 0;
    forn(i, 0, N) sum[0][i] = 0;
    forn(i, 1, N) {
        dp[i][2] = Add(sum[i - 1][2], 1);
        forn(j, 3, N)
            dp[i][j] = Add(dp[i][j - 1], sum[i - 1][j]);
        sum[i][0] = dp[i][0];
        forn(j, 1, N)
            sum[i][j] = Add(sum[i][j - 1], dp[i][j]);
    }
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    forn(i, 0, n)
        fore(j, 2, m) {
            ans += (m - j + 1) * dp[i + 1][j] % MOD * (dp[n - i][j] - dp[n - i - 1][j] + MOD);
            ans %= MOD;
        }
    cout << ans << '\n';
}