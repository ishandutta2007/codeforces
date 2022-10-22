#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();
    int n;
    cin >> n;
    vector<int> a(n, 1);
    for (int i = 1; i < n; i++) {
        a[i] = (10 * a[i - 1]) % mod;
    }
    for (int l = 1; l <= n; l++) {
        if (l == n) {
            cout << 10 << " ";
            break;
        }
        int ans = 0;
        ans += 2 * 10 * 9 * a[n - l - 1];
        ans %= mod;
        int z = max(0ll, n - l - 1);
        ans += 10 * 9 * 9 * z * a[max(0ll, n - l - 2)];
        ans %= mod;
        cout << ans << " ";
    }
}