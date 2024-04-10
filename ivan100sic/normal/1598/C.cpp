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

        R::sort(a);

        ll s = accumulate(begin(a), end(a), 0ll);
        if (2*s % n) {
            cout << "0\n";
            continue;
        }

        s = 2*s / n;

        ll sol = 0;
        for (int i : ra(0, n)) {
            sol += R::equal_range(span(a).subspan(i+1, n-i-1), s - a[i]).size();
        }

        cout << sol << '\n';
    }
    
}