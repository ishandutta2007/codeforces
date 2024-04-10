#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll dp[1000005];

ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    cout << dp[n] * qpow(qpow(2, n), mod - 2) % mod;
}