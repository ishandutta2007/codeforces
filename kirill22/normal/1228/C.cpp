#include<bits/stdc++.h>

using namespace std;

#define int long long

int ans = 1, mod = 1e9 + 7;

int binpow(int a, int n) {
    a %= mod;
    if (n == 0) return 1ll;
    if (n == 1) {
        return a % mod;
    }
    if (n % 2 == 0) {
        return (binpow((a * a) % mod, n / 2)) % mod;
    }
    else {
        return (((binpow((a * a) % mod, n / 2)) % mod) * a) % mod;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, n;
    cin >> x >> n;
    vector<int> a;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            a.push_back(i);
        }
        while (x % i == 0) {
            x /= i;
        }
    }
    if (x != 1) {
        a.push_back(x);
    }
    for (auto c : a) {
        int res = 1;
        while (res <= (1e18 * 2) / c && res * c <= n) {
            res *= c;
        }
        int tmp = 0;
        while (res > 1) {
            int k = n / res;
            ans = ((ans * binpow(res, k - tmp)) % mod);
            //cout << (binpow(res, k - tmp)) % mod << " " << res << " " << k - tmp << endl;
            if (ans < 0){
                ans += mod;
            }
            tmp = k;
            res /= c;
        }
    }
    if (ans < 0) {
            ans += mod;
    }
    cout << ans << endl;
}