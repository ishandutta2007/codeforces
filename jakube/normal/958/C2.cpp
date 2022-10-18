#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, p;
    cin >> n >> k >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= p;
    }
    vector<int> psum(v.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < v.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + v[psum_idx];
    }

    vector<vector<int>> dp(k+1, vector<int>(n+1, std::numeric_limits<int>::min()));
    dp[0][0] = 0;
    for (int K = 1; K <= k; K++) {
        vector<int> f(p, std::numeric_limits<int>::min());
        for (int i = 1; i <= n; i++) {
            f[0] = max(f[0], dp[K-1][i-1]);
            rotate(f.begin(), f.begin() + (p - v[i-1]) % p, f.end());
            for (int j = 0; j < p; j++)
                dp[K][i] = max(dp[K][i], f[j] + j);
        }
    }

    cout << dp[k][n] << endl;
}