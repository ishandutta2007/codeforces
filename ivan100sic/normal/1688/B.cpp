// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int rankk(ull x) {
    int t = 0;
    while (x % 2 == 0) {
        t++;
        x /= 2;
    }
    return t;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }

        int odd = R::count_if(a, [](int x) { return x % 2 == 1; });

        if (odd > 0) {
            cout << n - odd << '\n';
        } else {
            cout << R::min(R::transform_view(a, rankk)) + n-1 << '\n';
        }
    }
}