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

const int N = 1000000;
const int LOG = 6;
ll dp[3][N];
int pows[LOG];
ll ans[N];

int digit(int n, int k) {
    return n / pows[k] % 10;
}

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
    int n;
    scanf("%d", &n);
    forn(i, 0, n) {
        ll x;
        scanf("%lld", &x);
        ++dp[0][x];
        dp[1][x] += x;
        dp[2][x] += x * x % MOD;
    }
    pows[0] = 1;
    forn(i, 1, LOG) pows[i] = 10 * pows[i - 1];
    forn(i, 0, 3) forn(j, 0, N) dp[i][j] %= MOD;
    forn(i, 0, 3) {
        forn(d, 0, LOG) {
            ford(x, 0, N) {
                if (digit(x, d) == 0) continue;
                int y = x - pows[d];
                dp[i][y] += dp[i][x];
                if (dp[i][y] >= MOD) dp[i][y] -= MOD;
            }
        }
    }
    forn(i, 0, N) {
        if (dp[0][i] == 0) {
            ans[i] = 0;
            continue;
        }
        if (dp[0][i] == 1) {
            ans[i] = dp[2][i];
            continue;
        }
        ans[i] = (dp[1][i] * dp[1][i] + dp[2][i]) % MOD * Pow(2, dp[0][i] - 2) % MOD;
    }
    forn(d, 0, LOG) {
        forn(x, 0, N) {
            if (digit(x, d) == 9) continue;
            int y = x + pows[d];
            ans[x] -= ans[y];
            if (ans[x] < 0) ans[x] += MOD;
        }
    }
    ll rez = 0;
    forn(i, 0, N) {
        rez ^= (1ll * i * ans[i]);
    }
    printf("%lld\n", rez);
}