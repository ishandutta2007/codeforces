#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    sort(v.begin(), v.end());

    map<int, int> cnt;
    for (int x : v) {
        cnt[x]++;
    }
    vector<pair<int, int>> vp(cnt.begin(), cnt.end());
    n = vp.size();
    
    vector<vector<int>> dp(n, vector<int>(k+1, std::numeric_limits<int>::min() / 2)); // <=
    dp[0][0] = 0;
    dp[0][1] = vp[0].second;
    for (int i = 1; i < n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= k; j++) {
            auto& x = dp[i][j];
            x = dp[i-1][j];
            int y = i;
            int sum = vp[i].second;
            x = max(x, sum + dp[i-1][j-1]);
            while (y > 0 && vp[i].first - vp[y-1].first <= 5) {
                y--;
                sum += vp[y].second;
                x = max(x, sum + (y > 0 ? dp[y-1][j-1] : 0));
            }
        }
    }
    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << '\n';
}