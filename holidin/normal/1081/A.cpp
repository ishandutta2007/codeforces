#include <bits/stdc++.h>
using namespace std;

int dp[1500], i, j, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n > 800) {
        cout << 1;
        return 0;
    }
    dp[1] = 1;
    for (i = 2; i <= 1000; ++i) {
        dp[i] = i;
        for (j = 1; j < i; ++j)
        if (i % j != 0)
            dp[i] = min(dp[i], i - j);
    }
    cout << dp[n];
}