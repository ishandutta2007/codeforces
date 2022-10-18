#include <bits/stdc++.h>
using namespace std;

void maxx(long long & x, long long y) {
    x = max(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> shrubs(n);
    for (auto& x : shrubs)
        cin >> x.first >> x.second;
    
    vector<long long> dp(k, std::numeric_limits<long long>::min());
    dp[0] = 0;

    long long ab_mod = 0;
    for (auto shrub : shrubs) {
        vector<long long> dp2(k, std::numeric_limits<long long>::min());
        for (int rem_a = 0; rem_a < k && rem_a <= shrub.first; rem_a++) {
            // shrub leaves rem_a from color red
            int tmp = shrub.first + shrub.second - rem_a;
            int full = tmp / k;
            int rem_b = tmp % k;
            /* if (full == 0 && rem_a != shrub.first) */
            if (rem_b > shrub.second)
                continue;
            // and leaves rem_b from color blue

            for (int a = 0; a < k; a++) {
                // total remaining
                int b = (ab_mod + k - a) % k;
                long long total = dp[a] + full;
                int new_a = rem_a + a;
                if (new_a >= k) {
                    new_a -= k;
                    total++;
                }
                int new_b = b + rem_b;
                if (new_b >= k) {
                    new_b -= k;
                    total++;
                }
                maxx(dp2[new_a], total);
            }
        }
        ab_mod = (ab_mod + shrub.first + shrub.second) % k;
        dp2.swap(dp);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}