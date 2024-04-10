#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    int mx = 0;
    LL sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    int z = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] != mx)
            z = __gcd(z, mx - a[i]);
    z = abs(z);
    cout << (static_cast<LL>(mx) * n - sum) / z << ' ' << z << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}