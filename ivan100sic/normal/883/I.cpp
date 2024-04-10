// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, k;
int a[300005], z[300005]; // z[i] = sum dp[0] .. dp[i-1]

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;
    for (int i : ra(0, n)) cin >> a[i];
    sort(a, a+n);

    cout << *R::lower_bound(R::iota_view(0, 1123123123), true, {}, [&](int m) {
        int j = 0;

        if (m < 90) {
            int x = 5;
        }

        // dp[0] = 0
        z[1] = 1;
        for (int i : ra(1, n+1)) {
            // solving dp[i+1]
            while (a[i-1] - a[j] > m) j++;
            int dpi = 0;
            if (i-j >= k && z[i-k+1] != z[j]) {
                dpi = 1;
            }
            z[i+1] = z[i] + dpi;
        }

        return z[n+1] > z[n];
    }) << '\n';
}