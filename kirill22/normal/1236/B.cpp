#include<bits/stdc++.h>

using namespace std;

#define int long long

int binpow(int a, int n, int mod) {
    a %= mod;
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return binpow((a * a) % mod, n / 2, mod);
    }
    else {
        return (binpow((a * a) % mod, n / 2, mod) * a) % mod;
    }
}

signed main() {
    int n, m, mod = 1e9 + 7;
    cin >> n >> m;
    int ans = 1;
    int x = binpow(2, m, mod);
    x -= 1;
    cout << binpow(x, n, mod);

}