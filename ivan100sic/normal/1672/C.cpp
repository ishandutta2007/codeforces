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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int l = 123123123, r = -1;
        for (int i : ra(0, n-1)) {
            if (a[i] == a[i+1]) {
                l = min(l, i);
                r = i;
            }
        }

        if (r == -1 || l == r) {
            cout << "0\n";
        } else {
            cout << max(1, r-l-1) << '\n';
        }
    }
}