#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using v1 = vector<ll>;
using v2 = vector<v1>;
using v3 = vector<v2>;
using v4 = vector<v3>;
using v5 = vector<v4>;
using v6 = vector<v5>;
const ll INF = 1e18;

int main() {
    int n = 0, K = 0;
    cin >> n >> K;
    v1 L(n), R(n), c(K + 1);
    for (int i = 0; i < n; i++) cin >> L[i] >> R[i];
    for (int i = 0; i < K; i++) cin >> c[i];
    auto calc = [&n, &L, &R, &c](int d, int l, int r, int x, int y, int f, int g) {
        if (d < 0 || l < 0 || r > n - 1) return 0ll;
        ll a = (!x ? L[l] : R[l]), b = (!y ? L[r] : R[r]);
        return ((((a >> d) & 1) ^ f) != (((b >> d) & 1) ^ g) ? c[d] : 0ll);
    };
    auto check = [&L, &R](int k, int d, int t) {
        if (d == -1) return true;
        if (t == 0) return ((L[k] >> d) & 1) == 0 && (L[k] >> (d + 1)) < (R[k] >> (d + 1));
        else return ((R[k] >> d) & 1) == 1 && (L[k] >> (d + 1)) < (R[k] >> (d + 1));
    };
    v6 dp(K + 2, v5(n + 2, v4(n + 2, v3(2, v2(2, v1(2, -1))))));
    function<ll(int, int, int, int, int, int)> solve = [&check, &calc, &dp, &solve, &K](int d, int l, int r, int x,
                                                                                        int y,
                                                                                        int f) -> ll {
        if (d == K + 1) return (l > r ? 0 : INF);
        if (~dp[d + 1][l + 1][r + 1][x][y][f]) return dp[d + 1][l + 1][r + 1][x][y][f];
        ll v = calc(d, l - 1, r + 1, x, y, f, 0);
        ll res = solve(d + 1, l, r, x, y, 0) + v;
        for (int k = l; k <= r; k++)
            for (int t = 0; t <= 1; t++) {
                if (!check(k, d, t)) continue;
                ll xx = solve(d + 1, l, k - 1, x, t, 0);
                ll vv = calc(d, l - 1, k, x, t, f, 1);
                ll yy = solve(d, k + 1, r, t, y, 1);
                res = min(res, xx + vv + yy);
            }
        dp[d + 1][l + 1][r + 1][x][y][f] = res;
        return res;
    };
//    cout << check(0, 1, 1) << endl;
//    cout << solve(1, 1, 0, 1, 1, 1) << endl;
//    cout << solve(1, 0, 0, 0, 1, 0) << endl;
//    cout << solve(2, 1, 2, 0, 0, 0) << endl;
    cout << solve(-1, 0, n - 1, 0, 0, 0) << endl;
    return 0;
}