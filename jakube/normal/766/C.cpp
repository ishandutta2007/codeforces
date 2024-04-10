#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(26);
    for (int i = 0; i < 26; i++) {
        cin >> v[i];
    }

    vector<vector<int>> pcounts(n+1, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            pcounts[i+1][j] = pcounts[i][j] + (s[i] - 'a' == j);
        }
    }
    
    vector<long long> dp(n+1, 0), dp2(n+1, numeric_limits<int>::max());
    int ma = 0;
    dp[0] = 1;
    dp2[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            bool b = true;
            for (int c = 0; c < 26; c++) {
                if (pcounts[i][c] - pcounts[j][c]) {
                    b &= i - j <= v[c];
                }
            }
            if (b) {
                dp[i] = (dp[i] + dp[j]) % MOD;
                ma = max(ma, i - j);
                dp2[i] = min(dp2[i], dp2[j] + 1);
            }
        }
    }

    cout << dp.back() << endl;
    cout << ma << endl;
    cout << dp2.back() << endl;

    return 0;
}