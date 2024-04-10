#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int a[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll ans = 0;
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < 2 * n; ++j) {
                cin >> a[i][j];
                if (j >= n && i >= n) {
                    ans += a[i][j];
                }
            }
        }
        ll ans2 = 1e18;
        for (int q = 0; q < 2; ++q) {
            int si = n * q;
            int sj = n * (1 - q);
            for (int i = 0; i < n; i += max(1, n - 1)) {
                for (int j = 0; j < n; j += max(1, n - 1)) {
                    ans2 = min<ll>(ans2, a[si + i][sj + j]);
                }
            }
        }
        ans += ans2;
        cout << ans << "\n";
    }


}