#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (int b = x; b <= y; ++b) {
        if (l <= k * b && k * b <= r) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}