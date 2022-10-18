#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 1'000'000;
    vector<vector<int>> dp(10, vector<int>(N + 1, 0));
    vector<int> g(N + 1);
    for (int i = 1; i <= N; i++) {
        if (i < 10) {
            g[i] = i;
        } else {
            int prod = 1;
            int num = i;
            while (num) {
                if (num % 10)
                    prod *= num % 10;
                num /= 10;
            }
            g[i] = g[prod];
        }
        
        for (int j = 0; j < 10; j++) {
            dp[j][i] = dp[j][i-1];
        }
        dp[g[i]][i]++;
    }

    int Q;
    cin >> Q;
    while (Q --> 0) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << dp[k][r] - dp[k][l-1] << '\n';
    }
}