#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> len(n);
    vector<vector<vector<int>>> at(n);
    vector<int> min_delta(n);
    vector<int> delta(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        len[i] = (int)s[i].size();
        at[i].resize(2 * len[i] + 1);
        int b = len[i];
        for (int j = 0; j < len[i]; ++j) {
            b += (s[i][j] == '(' ? 1 : -1);
            at[i][b].push_back(j + 1);
            min_delta[i] = min(min_delta[i], b - len[i]);
        }
        delta[i] = b - len[i];
    }
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    int ans = 0;
    for (int t = 0; t < (1 << n); ++t) {
        if (dp[t] == -1) {
            continue;
        }
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (t & (1 << i)) {
                cur += delta[i];
            }
        }
        assert(cur >= 0);
        for (int i = 0; i < n; ++i) {
            if (t & (1 << i)) {
                continue;
            }
            int goal = len[i] - cur;
            int ft = dp[t];
            if (cur + min_delta[i] < 0) {
                assert(goal > 0 && goal <= 2 * len[i]);
                assert(!at[i][goal - 1].empty());
                int bound = at[i][goal - 1][0];
                ft += (int)(lower_bound(at[i][goal].begin(), at[i][goal].end(),
                                        bound) -
                            at[i][goal].begin());
                ans = max(ans, ft);
                continue;
            }
            if (goal >= 0 && goal <= 2 * len[i]) {
                ft += (int)at[i][goal].size();
            }
            dp[t | (1 << i)] = max(dp[t | (1 << i)], ft);
        }
    }
    ans = max(ans, dp.back());
    cout << ans << '\n';
    return 0;
}