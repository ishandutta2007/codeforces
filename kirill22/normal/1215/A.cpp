#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, a2, k, k2, n;
    cin >> a >> a2 >> k >> k2 >> n;
    if (k2 < k) {
        swap(k, k2);
        swap(a, a2);
    }
    int x = a * (k - 1) + a2 * (k2 - 1);
    if (x >= n) {
        cout << 0 << " ";
    }
    else {
        cout << min(a + a2, n - x) << " ";
    }
    if (n < a * k) {
        cout << n / k;
    }
    else {
        int ans = a;
        n -= a * k;
        cout << ans + min(a2, n / k2);
    }
}