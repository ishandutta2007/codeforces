#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;
    int k;
    cin >> k;

    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (k == 1) {
        if (n == "1")
            cout << 0 << '\n';
        else
            cout << n.size() - 1 << '\n';
        return 0;
    }

    int PRE_C = 10;
    int PRE = (1 << PRE_C) + 1;
    vector<int> precalc(PRE, 0);
    for (int i = 2; i < PRE; i++) {
        precalc[i] = precalc[__builtin_popcount(i)] + 1;
    }

    if ((int)n.size() <= PRE_C) {
        int val = 0;
        for (char c : n) {
            val = val * 2 + (c - '0');
        }
        int cnt = 0;
        for (int i = 1; i <= val; i++) 
            if (precalc[i] == k)
                cnt++;
        cout << cnt << endl;
    } else {
        vector<int> set_digits;
        for (int i = 1; i < PRE; i++) {
            if (precalc[i] == k - 1) {
                set_digits.push_back(i);
            }
        }

        int MOD = 1'000'000'007;
        int m = n.size();
        vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(m + 1, vector<long long>(2, 0)));
        dp[0][0][1] = 1;
        for (int i = 1; i <= m; i++) {
            dp[i][0][0] = 1;
            dp[i][0][1] = 0;
            for (int j = 1; j <= i; j++) {
                // smaller
                // zero
                dp[i][j][0] += dp[i-1][j][0]; 
                dp[i][j][0] += dp[i-1][j-1][0]; 
                if (n[i-1] == '1')
                    dp[i][j][0] += dp[i-1][j][1];
                dp[i][j][0] %= MOD;

                // equal
                if (n[i-1] == '1')
                    dp[i][j][1] = dp[i-1][j-1][1];
                else
                    dp[i][j][1] = dp[i-1][j][1];
            }
        }

        long long cnt = 0;
        for (int digits : set_digits) {
            if (digits <= m)
                cnt += dp[m][digits][0] + dp[m][digits][1];
        }
        cout << cnt % MOD << '\n';
        
    }

}