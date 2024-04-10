#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <vector>
using namespace std;
using lint = long long;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main() {
    int N, M, K, P;
    cin >> N >> M >> K >> P;

    if (K > N / 2 + 2) {
        puts("0");
        return 0;
    }

    vector ncr(120, vector<lint>(120));
    REP(i, ncr.size()) ncr[i][0] = 1;
    FOR(i, 1, ncr.size()) FOR(j, 1, ncr[i].size()) {
        ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % P;
    }

    vector<lint> fac(102, 1);
    FOR(i, 1, fac.size()) fac[i] = fac[i - 1] * i % P;

    vector dp(N + 1, vector<lint>(K + 1));
    REP(i, dp.size()) dp[i][i > 0] = fac[i];

    FOR(l, 2, M + 1) {
        vector dpnxt(dp.size(), vector<lint>(dp[0].size()));
        dpnxt[0][0] = 1;
        FOR(n, 1, N - (M - l) + 1) REP(i, n) {
            REP(k, K + 1) {
                __int128 su = 0;
                REP(kk, k + 1) {
                    su += dp[i][kk] * dp[n - 1 - i][k - kk];
                }
                dpnxt[n][k] += su % P * ncr[n - 1][i];
                dpnxt[n][k] %= P;
            }
        }
        dp = dpnxt;
    }
    cout << dp[N][K] << '\n';
}