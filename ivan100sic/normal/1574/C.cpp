// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
ll a[200005], sum;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+n);

    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        // if we can slay him, do so
        auto it = lower_bound(a, a+n, x);
        if (it != a+n) {
            ll cost1 = max(0ll, y - (sum - *it));
            ll cost2 = 8e18;
            if (it != a) {
                --it;
                cost2 = max(0ll, y - (sum - *it)) + (x - *it);
            }
            cout << min(cost1, cost2) << '\n';
        } else {
            ll cost = 0;
            cost += x - a[n-1];
            ll sum2 = sum - a[n-1];
            cost += max(0ll, y - sum2);
            cout << cost << '\n';
        }
    }
}