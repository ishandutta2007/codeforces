#include <bits/stdc++.h>
using namespace std;

const long long M = (1 << 20);

int n;
int dp[M], fail[M], numlen[M];

string str;

int main() {
    cin >> str;
    n = str.size();
    str = "#" + str;
    for (int j = 1; j <= n; ++j) {
        int x = j;
        while (x > 0) ++numlen[j], x /= 10;
    }
    for (int j = 2; j <= n + 1; ++j) dp[j] = (1 << 20);
    dp[1] = 0;
    for (int j = 1; j <= n; ++j) {
        fail[j] = 0;
        for (int i = j + 1; i <= n; ++i) {
            fail[i] = 0;
            int k = fail[i - 1];
            while (1) {
                if (str[i] == str[j + k]) {
                    fail[i] = k + 1;
                    break;
                }
                if (k == 0) break;
                k = fail[j + k - 1];
            }
        }
        for (int i = j; i <= n; ++i) {
            int len = i - j + 1;
            int f = fail[i];
            int P = 1;
            if (len % (len - f) == 0) P = len / (len - f);
            dp[i + 1] = min(dp[i + 1], dp[j] + numlen[P] + len / P);
        }
    }
    cout << dp[n + 1] << endl;
    return 0;
}