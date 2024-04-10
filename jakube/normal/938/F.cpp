#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    int k = log2(n);

    vector<vector<int>> missing(1 << k);
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) {
            if ((i & (1 << j)) == 0)
                missing[i].push_back(1 << j);
        }
    }

    vector<vector<bool>> dp(n+1, vector<bool>(1<<k, false));
    vector<pair<int, int>> opt;
    dp[0][0] = true;
    opt.push_back({0, 0});

    int final_len = n - (1 << k) + 1;
    string ans = "";
    for (int p = 0; p < final_len; p++) {
        // first expand
        for (int i = 0; i < (int)opt.size(); i++) {
            auto [len, mask] = opt[i];
            for (int mi : missing[mask]) {
                if (len + mi <= n && !dp[len + mi][mask | mi]) {
                    dp[len + mi][mask | mi] = true;
                    opt.push_back({len + mi, mask | mi});
                }
            }
        }

        // find next char
        char m = 'z';
        for (auto [i, mask] : opt) {
            if (s[i] < m)
                m = s[i];
        }
        ans += m;

        // get next opts
        vector<pair<int, int>> opt2;
        for (auto [i, mask] : opt) {
            if (s[i] == m) {
                dp[i + 1][mask] = true;
                opt2.push_back({i + 1, mask});
            }
        }
        opt = opt2;
    }

    cout << ans << endl;
}