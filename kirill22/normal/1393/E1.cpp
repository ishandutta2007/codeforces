#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

void sum(int& x, int y) {
    x = (x + y) % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n);
    dp[0].resize(a[0].size() + 1);
    for (auto& x : dp[0]) x = 1;
    for (int i = 1; i < n; i++) {
        dp[i].resize(a[i].size() + 1);
        for (int j = 0; j <= a[i - 1].size(); j++) {
            string s;
            if (j < a[i - 1].size()) s = a[i - 1].substr(0, j) + a[i - 1].substr(j + 1, (int) a[i - 1].size() - j - 1);
            else s = a[i - 1];
            string s2 = a[i].substr(1, (int) a[i].size() - 1);
            int pos = 0;
            while (pos < min(s.size(), s2.size()) && s[pos] == s2[pos]) pos++;
            for (int k = 0; k < a[i].size(); k++) {
                if (k) {
                    s2[k - 1] = a[i][k - 1];
                    if (k - 1 < pos) {
                        if (s[k - 1] != s2[k - 1]) pos = k - 1;
                    }
                    else if (k - 1 == pos && pos != s.size()) {
                        while (pos < min(s.size(), s2.size()) && s[pos] == s2[pos]) pos++;
                    }
                }
                if (pos == s.size()) {
                    sum(dp[i][k], dp[i - 1][j]);
                }
                else {
                    if (pos != s2.size() && s[pos] < s2[pos]) {
                        sum(dp[i][k], dp[i - 1][j]);
                    }
                }
            }
            if (a[i] >= s) {
            	sum(dp[i][a[i].size()], dp[i - 1][j]);
            }
        }
    }
    int x = 0;
    for (int i = 0; i <= a[n - 1].size(); i++) sum(x, dp[n - 1][i]);
    cout << x;
}