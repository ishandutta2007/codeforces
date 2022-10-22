#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int a, b, t;
        cin >> a >> b >> t;
        if (a < b) swap(a, b);
        while (t--) {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            int p = a * b / __gcd(a, b);
            for (int k = 0; k < a; k++) {
                // x = abz + k
                int _l, _r;
                int z = l % p;
                if (z <= k) {
                    _l = l + (k - z);
                }
                else {
                    _l = l + (p - (z - k));
                }
                z = r % p;
                if (z >= k) {
                    _r = r - (z - k);
                }
                else {
                    _r = r - (p - (k - z));
                }
                if (_l <= _r) {
                    ans -= (_r - _l + p) / (p);
                }

            }
            ans += (r - l + 1);
            cout << ans << " ";
        }
        cout << '\n';
    }
}