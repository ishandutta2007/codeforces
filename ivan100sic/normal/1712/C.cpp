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

        string mark(n+1, 0);

        int r = 0;
        auto up = [&](int t) {
            while (r < t) {
                mark[a[r]] = 1;
                r++;
            }
        };

        for (int i : ra(1, n)) {
            if (mark[a[i]]) a[i] = 0;
            if (a[i-1] > a[i]) {
                up(i);
            }
        }

        cout << R::count(span(mark).subspan(1), 1) << '\n';
    }
}