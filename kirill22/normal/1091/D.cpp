#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

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

vector<int> fact, invfact;

int C(int n, int k) {
    return fact[n] * 1ll * invfact[k] % mod * invfact[n - k] % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fact.resize(n + 1, 1);
    invfact.resize(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * 1ll * i % mod;
    }
    invfact.back() = binpow(fact.back(), mod - 2);
    for (int i = n; i > 1; i--) {
        invfact[i - 1] = invfact[i] * 1ll * i % mod;
    }
    int ans = fact[n];
    for (int a = 1; a < n; a++) {
        ans = (ans + C(n, a) * 1ll * fact[a] % mod * (fact[n - a] - 1) % mod) % mod;
    }
    cout << ans;
}