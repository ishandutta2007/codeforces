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
        vector<int> a(10, -1);
        for (int i : ra(0, n)) {
            int b, d;
            cin >> b >> d;
            d--;
            a[d] = max(a[d], b);
        }

        if (R::count(a, -1)) {
            cout << "MOREPROBLEMS\n";
        } else {
            cout << accumulate(begin(a), end(a), 0) << '\n';
        }
    }
}