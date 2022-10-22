#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, mod;
        cin >> n >> mod;
        int ans = 1;
        int z = 1;
        while ((1ll << z) <= n) {
            int p = (1ll << z);
            ans = (ans * min(p + 1, n - (p) + 2)) % mod;
            //cout << ans << endl;
            z++;
        }
        cout << (ans * 2 - 1 + mod) % mod << endl;
    }
}