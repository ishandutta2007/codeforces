#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll dp[200005];

ll getn(int n) {
    ll k = 1;
    while (k * (k + 1) / 2 <= n) k++;
    return k - 1;
}

int main() {
    ll n, a, b;
    cin >> a >> b;
    n = a + b;
    ll g = getn(a + b);
    n = g * (g + 1) / 2;
    dp[0] = 1;
    g = getn(n);
    for (int i = 1; i <= g; i++) {
        for (int j = 200000; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= a; i++) {
        if (i + b < n) continue;
        ans = (ans + dp[i]) % mod;
    }
    cout << ans;
}