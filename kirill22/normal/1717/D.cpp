#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int binpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * 1ll * x % mod;
        }
        n >>= 1;
        x = x * 1ll * x % mod;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * 1ll * i % mod;
    }
    vector<int> ifact(n + 1, 1);
    ifact.back() = binpow(fact.back(), mod - 2);
    for (int i = n; i > 1; i--) {
        ifact[i - 1] = ifact[i] * 1ll * i % mod;
    }
    int ans = 0;
    for (int x = 0; x <= min(n, k); x++) {
        ans = (ans + fact[n] * 1ll * ifact[x] % mod * ifact[n - x]) % mod;
    }
    cout << ans;
}