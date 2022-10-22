#include<bits/stdc++.h>
 
using namespace std;
 
signed main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> dp(m, vector<int> (m, 0));
    for (int i = 1; i < n; i++) {
        dp[s[i] - 'a'][s[i - 1] - 'a']++;
        dp[s[i - 1] - 'a'][s[i] - 'a']++;
    }
    vector<int> DP(1 << m, 1e18);
    DP[0] = 0;
    for (int i = 0; i < (1 << m); i++) {
        int s = 1;
        for (int k = 0; k < m; k++) {
            if ((i & (1 << k))) {
                s++;
            }
        }
        for (int j = 0; j < m; j++) {
            //cout << i << " " << (1 << j) << " " << (i & (1 << j)) << endl;
            if ((i & (1 << j)) == 0) {
                int x = i | (1 << j), ans = 0;
                ans = DP[i];
                for (int k = 0; k < m; k++) {
                    if (k != j) {
                        if ((i & (1 << k))) {
                            ans += s * dp[j][k];
                        }
                        else {
                            ans -= s * dp[j][k];
                        }
                    }
                }
                DP[x] = min(DP[x], ans);
            }
        }
    }
    cout << DP[(1 << m) - 1];
}