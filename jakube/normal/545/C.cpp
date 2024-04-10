#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    vector<pair<int, int>> v(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> v[idx].first >> v[idx].second;
    
    vector<pair<int, int>> dp(n, {0, 0});
    dp[0] = {1, 1};
    for (int i = 1; i < n; ++i) {
        int left = dp[i-1].first;
        if (v[i-1].first + v[i-1].second < v[i].first) {
            left = max(left, dp[i-1].second);
        }
        if (v[i].first - v[i].second > v[i-1].first) {
            left = max(left, dp[i-1].first + 1);
        }
        if (v[i].first - v[i].second > v[i-1].first + v[i-1].second) {
            left = max(left, dp[i-1].second + 1);
        }

        int right = dp[i-1].first;
        if (v[i-1].first + v[i-1].second < v[i].first) {
            right = max(right, dp[i-1].second);
        }
        dp[i] = {left, right + 1};
    }
    
    cout << dp.back().second << endl;

    return 0;
}