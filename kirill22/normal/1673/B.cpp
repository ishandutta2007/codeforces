#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string ans = "YES";
        int n = (int) s.size();
        vector<int> pos[26];
        vector<vector<int>> dp(n + 1, vector<int> (26));
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            dp[i + 1][s[i] - 'a']++;
            pos[s[i] - 'a'].push_back(i);
        }
        for (int j = 0; j < 26; j++) {
            for (int i = 0; i + 1 < (int) pos[j].size(); i++) {
                for (int c = 0; c < 26; c++) {
                    if (c == j || !dp[n][c]) {
                        continue;
                    }
                    if (dp[pos[j][i + 1] + 1][c] - dp[pos[j][i]][c] == 0) {
                        ans = "NO";
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}