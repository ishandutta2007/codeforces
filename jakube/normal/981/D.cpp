#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<long long> psum(v.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < v.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + v[psum_idx];
    }
    auto sum = [&psum](int x, int y) {
        return psum[y+1] - psum[x];
    };

    long long res = 0;
    for (int bit = 60; bit >= 0; bit--) {
        res += 1LL << bit;
        // test res;
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
        dp[0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if ((res & sum(j, i)) == res) {
                    for (int K = 0; K < k; K++) {
                        if (dp[j][K])
                            dp[i+1][K+1] = true;
                    }
                }
            }
        }
        if (!dp[n][k])
            res -= 1LL << bit;
    }
    cout << res << '\n';
}