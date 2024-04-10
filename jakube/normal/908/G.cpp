#include <bits/stdc++.h>
using namespace std;

const int mod = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    vector<vector<long long>> dp(10, vector<long long>(n, 0));

    for (int digit = 1; digit < 10; digit++) {
        vector<vector<vector<long long>>> inter(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2, 0)));
        inter[0][0][1] = 1;
        for (int a = 1; a <= n; a++) {
            int cur = s[a-1] - '0';
            for (int b = 0; b <= a; b++) {
                // c = 0
                inter[a][b][0] += inter[a-1][b][0] * digit;
                if (b > 0)
                    inter[a][b][0] += inter[a-1][b-1][0] * (10 - digit);
                inter[a][b][0] += inter[a-1][b][1] * min(digit, cur);
                if (digit < cur && b > 0)
                    inter[a][b][0] += inter[a-1][b-1][1] * (cur - digit);
                inter[a][b][0] %= mod;

                // c = 1
                if (cur >= digit) {
                    if (b > 0)
                        inter[a][b][1] = inter[a-1][b-1][1];
                } else
                    inter[a][b][1] = inter[a-1][b][1];
            }
        }
        for (int b = 1; b <= n; b++) {
            dp[digit][b - 1] = inter[n][b][0] + inter[n][b][1];
        }
        for (int b = n; b > 0; b--) {
            dp[digit][b - 1] = inter[n][b][0] + inter[n][b][1];
            if (b < n)
                dp[digit][b - 1] += dp[digit][b];
            dp[digit][b-1] %= mod;
        }
    }

    long long sum = 0;
    for (int digit = 1; digit < 10; digit++) {
        long long base = 1;
        for (int i = 0; i < n; i++) {
            sum += dp[digit][i] * base % mod;
            base = base * 10 % mod;
        }
        sum %= mod;
    }
    cout << sum << endl;
}