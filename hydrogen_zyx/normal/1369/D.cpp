#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3000000];
const ll mod = 1e9 + 7;
int main() {
    dp[1] = 1;
    for (int i = 2; i <= 2000000; i++) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % mod;
    }
    for (int i = 3; i <= 2000000; i++) {
        dp[i] = (dp[i] + dp[i - 3]) % mod;
    }
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 3) {
            cout << 0 << endl;
            continue;
        }
        n -= 2;
        cout << dp[n] * 4 % mod << endl;
    }
}