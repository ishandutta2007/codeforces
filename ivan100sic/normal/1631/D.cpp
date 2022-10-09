// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        auto b = a;
        R::sort(a);

        // in - out >= k
        // in - (n - in) >= k
        // 2 in - n >= k
        // in >= (k + n) / 2
        int w = (k+n+1)/2, z = 1e9, zl = -1, zr = -1;
        for (int i : ra(0, n-w+1)) {
            int zi = a[i+w-1] - a[i];
            if (zi < z) {
                zl = a[i];
                zr = a[i+w-1];
                z = zr - zl;
            }
        }

        cout << zl << ' ' << zr << '\n';
        int made = 0, sum = 0, last = 1;
        if (k == 1) {
            cout << "1 " << n << '\n';
        } else {
            for (int i : ra(0, n)) {
                sum += (zl <= b[i] && b[i] <= zr) * 2 - 1;
                if (sum == 1) {
                    sum = 0;
                    made++;
                    cout << last << ' ' << i+1 << '\n';
                    last = i+2;
                    if (made == k - 1) {
                        cout << last << ' ' << n << '\n';
                        break;
                    }
                }
            }
        }
    }
}