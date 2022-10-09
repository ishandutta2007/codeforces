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

    int a[6];
    for (int& x : a) cin >> x;

    for (int p : ra(-100, 100)) {
        int q = a[0] - p;
        int r = a[2] - p;
        int s = a[4] - p;

        if (a[0] == p + q &&
            a[1] == r + s &&
            a[2] == p + r &&
            a[3] == q + s &&
            a[4] == p + s &&
            a[5] == q + r)
        {
            if (max({p, q, r, s}) > 9 || min({p, q, r, s}) < 1) {
                continue;
            }

            if (((set<int>{p, q, r, s})).size() != 4) continue;

            cout << p << ' ' << q << '\n';
            cout << r << ' ' << s << '\n';
            return 0;
        }
    }

    cout << "-1\n";
}