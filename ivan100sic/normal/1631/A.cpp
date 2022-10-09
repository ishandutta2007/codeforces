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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        int ah = R::max_element(a) - begin(a);
        int bh = R::max_element(b) - begin(b);

        if (a[ah] < b[bh]) {
            swap(a, b);
            swap(ah, bh);
        }

        int y = 0;
        for (int i : ra(0, n)) {
            if (i == ah) {
                y = max(y, b[i]);
            } else {
                y = max(y, min(a[i], b[i]));
            }
        }

        cout << a[ah] * y << '\n';
    }
}