#include <bits/stdc++.h>
using namespace std;

// dp2[length][eo][eo]
// dp3[length][eo][eo][eo]
// dp[length][eo^base]

vector<vector<vector<long long>>> dp;

long long f(int b, long long x) {
    // convert to base b
    vector<int> digits;
    while (x) {
        digits.push_back(x % b);
        x /= b;
    }
    reverse(digits.begin(), digits.end());

    if (digits.empty())
        return 0;

    long long result = 0;
    // smaller in length
    for (unsigned long length = 2; length < digits.size(); length += 2) {
        result += (b - 1) * (dp[b][length - 1][2]);
    }

    // equal in length, but still smaller
    int mask = 0;
    for (unsigned long digit = 0; digit < digits.size(); digit++) {
        int start = 0;
        if (digit == 0)
            start++;
        for (int d = start; d < digits[digit]; d++) {
            result += dp[b][digits.size() - digit - 1][mask ^ (1 << d)];
        }

        mask ^= (1 << digits[digit]);
    }

    if (mask == 0)
        result++;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp.assign(11, vector<vector<long long>>(64, vector<long long>(1024, 0)));
    // precompute
    for (int base = 2; base <= 10; base++) {
        auto &DP = dp[base];
        DP[0][0] = 1;
        for (int length = 1; length < 64; length++) {
            for (int digit = 0; digit < base; digit++) {
                for (int mask = 0; mask < (1 << base); mask++) 
                    DP[length][mask ^ (1 << digit)] += DP[length - 1][mask];
            }
        }
    }

    int n;
    cin >> n;
    while (n --> 0) {
        int b;
        cin >> b;
        long long l, r;
        cin >> l >> r;
        cout << f(b, r) - f(b, l - 1) << '\n';
    }
}