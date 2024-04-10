#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int n;
string s;
int dp[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    s = '.' + s;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return 0;
        }
        dp[i] = dp[i - 1];
        if (s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}