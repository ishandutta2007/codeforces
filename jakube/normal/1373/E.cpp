#include "bits/stdc++.h"
using namespace std;

long long best;
long long INF = std::numeric_limits<long long>::max() / 12;

vector<vector<vector<vector<long long>>>> dp;

long long f(int k, int equal, int rem, int last0) {
    if (rem == 0) {
        if (equal == k + 1)
            return 0;
        else
            return INF;
    }
    if (last0 > 1)
        return INF;

    if (dp[k][equal][rem][last0] != -1)
        return dp[k][equal][rem][last0];

    long long local_best = INF;
    int new_rem;
    for (int digit = 0; digit < 10; digit++) {
        if (k == 0 && digit == 0)
            continue;
        new_rem = rem;
        for (int i = 0; i <= k; i++) {
            if (i < equal)
                new_rem -= digit;
            else
                new_rem -= (digit + 1) % 10;
        }
        if (new_rem >= 0) {
            local_best = min(local_best,
                    10 * f(k, (digit < 9) ? k+1 : equal, new_rem, (digit==0) ? last0+1 : 0) + digit);
        }
    }
    new_rem = rem;

    dp[k][equal][rem][last0] = local_best;
    return local_best;
}

void solve() {
    int n, k;
    cin >> n >> k;
    best = INF;

    for (int start_digits = 0; start_digits < 10; start_digits++) {
        int rem = n;
        int equal = 0;
        for (int i = 0; i <= k; i++) {
            rem -= (start_digits + i) % 10;
            if (start_digits + i < 10)
                equal++;
        }
        if (rem >= 0) {
            long long prefix = f(k, equal, rem, 0);
            best = min(prefix * 10 + start_digits, best);
        }
    }
    
    if (best >= INF)
        cout << -1 << '\n';
    else
        cout << best << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    dp.assign(11, vector<vector<vector<long long>>>(11, vector<vector<long long>>(151, vector<long long>(2, -1))));

    /* const int INF = std::numeric_limits<int>::max(); */
    /* vector<vector<int>> dp(151, vector<int>(10, INF)); */
    /* for (int start = 0; start < 1'000'000; start++) { */
    /*     int cur = 0; */
    /*     for (int k = 0; k < 10; k++) { */
    /*         cur += digit_sum(start + k); */
    /*         if (cur <= 150) */
    /*             dp[cur][k] = min(dp[cur][k], start); */
    /*     } */
    /* } */

    /* auto es = [](int x, int y) { return (x + y) * (y - x + 1) / 2; }; */
    /* for (int k = 0; k <= 9; k++) { */
    /*     for (int i = 1; i <= 150; i++) { */
    /*         if (es(0, k) + (k + 1) > i) */
    /*             dp[i][k] = -1; */
    /*         if (dp[i][k] == INF) */
    /*             cout << i << ", " << k << '\n'; */
    /*     } */
    /* } */

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}