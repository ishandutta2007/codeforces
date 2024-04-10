#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    
    vector<int> psum(a.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < a.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + a[psum_idx];
    }
    auto sum = [&psum](int x, int y) {
        return psum[y+1] - psum[x];
    };

    vector<map<int, int>> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i+1] = dp[i];
        int sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += a[j];
            dp[i+1][sum] = max(dp[i+1][sum], dp[j][sum] + 1);
        }
    }

    int mx = 0;
    int cnt = 0;
    for (auto [val, c] : dp[n]) {
        if (c >= cnt) {
            cnt = c;
            mx = val;
        }
    }
    cout << cnt << '\n';
    int i = n;
    while (i > 0) {
        if (dp[i][mx] > dp[i-1][mx]) {
            int j = i - 1;
            int sum = a[j];
            while (sum != mx) {
                j--;
                sum += a[j];
            }
            cout << j + 1 << " " << i << '\n';
            i = j;
        } else {
            i--;
        }
    }
}