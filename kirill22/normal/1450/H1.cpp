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
 
int C(int n, int k, const vector<int>& fact, const vector<int>& invfact) {
    return fact[n] * 1ll * invfact[k] % mod * invfact[n - k] % mod;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> fact(n + 1, 1), invfact(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * 1ll * i % mod;
    }
    invfact.back() = binpow(fact.back(), mod - 2);
    for (int i = n; i >= 2; i--) {
        invfact[i - 1] = invfact[i] * 1ll * i % mod;
    }
    int ans = 0;
    int x = 0, y = 0, cx = 0, cy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            if (i % 2) {
                x++;
            } else {
                y++;
            }
        }
        if (s[i] == '?') {
            if (i % 2) {
                cx++;
            } else {
                cy++;
            }
        }
    }
    for (int i = 0; i <= cx + cy; i++) {
        if (abs(i - cy + x - y) % 2 != 0) {
            continue;
        }
        ans = (ans + C(cy + cx, i, fact, invfact) * 1ll * abs(i - cy + x - y)) % mod;
    }
    cout << ans * 1ll * binpow(binpow(2, cx + cy), mod - 2) % mod;
}