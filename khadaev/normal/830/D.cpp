#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 444;
ll dp[N][N];

ll calc(int n, int k) {
    if (k == 0) return 1;
    if (n == 1) {
        if (k == 1) return 1;
        else return 0;
    }
    ll ans = 0;
    /*fore(i, 0, k) {
        ans += dp[n - 1][i] * dp[n - 1][k - i];
        ans %= MOD;
    }
    fore(i, 1, k) {
        ans += 4 * dp[n - 1][i] * dp[n - 1][k - i] % MOD * i;
        ans %= MOD;
    }
    fore(i, 0, k - 1) {
        ans += dp[n - 1][i] * dp[n - 1][k - 1 - i];
        ans %= MOD;
    }
    fore(i, 1, k) {
        ans += 2 * dp[n - 1][i] * dp[n - 1][k + 1 - i] % MOD * i % MOD * (k + 1 - i) % MOD;
        ans %= MOD;
    }
    fore(i, 2, k + 1) {
        ans += 2 * dp[n - 1][i] * dp[n - 1][k + 1 - i] % MOD * i % MOD * (i - 1) % MOD;
        ans %= MOD;
    }*/


    fore(i, 0, k) {
        ans += dp[n - 1][i] * dp[n - 1][k - i] % MOD * (4 * i + 1);
        ans %= MOD;
    }
    fore(i, 0, k - 1) {
        ans += dp[n - 1][i] * dp[n - 1][k - 1 - i];
        ans %= MOD;
    }
    fore(i, 1, k + 1) {
        ans += 2 * dp[n - 1][i] * dp[n - 1][k + 1 - i] % MOD * i % MOD * k;
        ans %= MOD;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fore(i, 1, N - 10) fore(j, 0, N - 10 - i) dp[i][j] = calc(i, j);
    int n;
    cin >> n;
    cout << dp[n][1] << '\n';
}