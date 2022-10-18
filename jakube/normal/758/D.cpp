#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int base;
    cin >> base;
    string s;
    cin >> s;
    
    vector<long long> dp(s.size() + 1);
    dp[0] = 0;
    long long MAX = 1e18;

    for (int i = 0; i < s.size(); i++) {
        dp[i+1] = MAX;
        for (int j = 0; j <= i; j++) {
            long long number = 0;
            bool b = true;
            for (int k = j; k <= i; k++) {
                if (k == j && k != i && s[k] == '0') {
                    b = false;
                    break;
                }
                if (number > (MAX + '0' - s[k] + 9) / 10) {
                    b = false;
                    break;
                }
                number = 10 * number + s[k] - '0';
            }

            if (b && number < base) {
                if (dp[j] <= (dp[i+1] - number + base - 1) / base) {
                    dp[i+1] = min(dp[i+1], dp[j] * base + number);
                }
            }
        }
    }

    cout << dp.back() << endl;

    return 0;
}