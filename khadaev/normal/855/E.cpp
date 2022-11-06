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

ll dp[11][60][11];
ll c[11][11];

ll solve(int b, ll x) {
    int msk = 0;
    vector<int> dig;
    while (x) {
        dig.eb(x % b);
        x /= b;
    }
    reverse(all(dig));
    ll ans = 0;
    int sz = dig.size();
    forn(i, 0, sz) {
        ans += dp[b][i][0];
        if (i) ans -= dp[b][i - 1][1] / b;
        //cerr << "DP: " << b << ' ' << i << ' ' << 0 << '\n';
        //cerr << dp[b][i][0] << '\n';
    }
    forn(i, 0, sz) {
        forn(j, 0, dig[i]) {
            int nw_msk = msk ^ (1 << j);
            if (i == 0 && j == 0) continue;
            ans += dp[b][sz - i - 1][__builtin_popcount(nw_msk)] / c[b][__builtin_popcount(nw_msk)];
            //cerr << "DP: " << b << ' ' << sz - i - 1 << ' ' << __builtin_popcount(nw_msk) << '\n';
            //cerr << dp[b][sz - i - 1][__builtin_popcount(nw_msk)] << '\n';

        }
        msk ^= (1 << dig[i]);
    }
    return ans;
}

void precalc() {
    fore(b, 2, 10) {
        dp[b][0][0] = 1;
        forn(i, 1, 60) fore(j, 0, b) {
            if (j > 0)
                dp[b][i][j] += dp[b][i - 1][j - 1] * (b - j + 1);
            if (j < b)
                dp[b][i][j] += dp[b][i - 1][j + 1] * (j + 1);
        }
    }
    c[0][0] = 1;
    forn(i, 1, 11) {
        c[i][0] = 1;
        c[i][i] = 1;
        forn(j, 1, i)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    precalc();
    int q;
    cin >> q;
    while (q--) {
        int b;
        cin >> b;
        ll l, r;
        cin >> l >> r;
        cout << solve(b, r + 1) - solve(b, l) << '\n';
    }
}