#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> dp(50);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            vector<long long> dp2(50, -(long long) 1e18);
            for (int j = 0; j < 50; j++) {
                if (j) {
                    x /= 2;
                }
                dp2[j] = max(dp2[j], dp[j] + x - k);
                dp2[min(49, j + 1)] = max(dp2[min(49, j + 1)], dp[j] + x / 2);
                
            }
            dp = dp2;
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
}