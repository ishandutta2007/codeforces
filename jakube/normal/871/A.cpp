#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    if (x == 2 || x == 3)
        return true;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    vector<int> dp(100, 0);
    dp[0] = -1;
    dp[1] = -1;
    dp[2] = -1;
    dp[3] = -1;
    dp[4] = 1;
    dp[5] = -1;
    for (int i = 6; i < dp.size(); i++) {
        int best = -1;
        if (!isPrime(i)) {
            best = 1;
        }
        dp[i] = best;

        for (int j = 4; j < i; j++) {
            if (!isPrime(j) && dp[i - j] > 0)
                dp[i] = max(dp[i], dp[i - j] + 1);
        }
        //         cout << i << ": " << dp[i] << endl;
    }

    while (q-- > 0) {
        int n;
        cin >> n;

        if (n < 100) {
            cout << dp[n] << '\n';
        } else {
            int x = (n - 80) / 4;
            n -= x * 4;
            cout << dp[n] + x << '\n';
        }
    }
}