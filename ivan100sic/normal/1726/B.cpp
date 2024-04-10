// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

vector<int> solve(int n, int m) {
    vector<int> a(n);

    if (n > m) return {};
    if (m % 2 == 1) {
        if (n % 2 == 0) return {};
        fill(begin(a), end(a) - 1, 1);
        a[n-1] = m-(n-1);
    } else {
        if (n % 2 == 0) {
            fill(begin(a), end(a) - 2, 1);
            int q = (m-(n-2)) / 2;
            a[n-2] = a[n-1] = q;
        } else {
            fill(begin(a), end(a) - 1, 1);
            a[n-1] = m-(n-1);
        }
    }

    return a;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        auto s = solve(n, m);
        if (s.empty()) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (int x : s) cout << x << ' ';
            cout << '\n';
        }
    }
}