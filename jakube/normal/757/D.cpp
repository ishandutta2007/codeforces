#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int add(int &a, int b) {
    a += b;
    if (a > MOD)
        a -= MOD;
}

int MAX_STATE = 20;

vector<vector<int>> calc_dp(string s, int n) {
    vector<vector<int>> dp(n+1, vector<int>(1 << MAX_STATE, 0));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
        bool positiv = false;
        int number = 0;
        for (int j = i; j >= 0; j--) {
            if (s[j] == '1') {
                positiv = true;
                if (i - j >= 10) break;
                number += 1 << (i - j);
            }

            if (positiv && number <= MAX_STATE) {
                int x = 1 << (number - 1);
                for (int state = 0; state < dp[i+1].size(); state++) {
                    add(dp[i+1][state | x], dp[j][state]);
                }
            }
        }
    }

    return dp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<vector<int>> dp = calc_dp(s, n);

    int total = 0;
    for (int i = 0; i <= n; i++) {
        int state = 0;
        for (int num = 1; num <= MAX_STATE; num++) {
            state |= 1 << (num - 1);
            add(total, dp[i][state]);
        }
    }

    cout << total << endl;

    return 0;
}