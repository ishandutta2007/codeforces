// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

constexpr auto rem(int m) {
    return [m](int x) {
        return ((1 << (x % 3)) & m) != 0;
    };
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        int h = *R::max_element(a);

        int sol = h;
        for (int c1 : ra(0, 3)) {
            for (int c2 : ra(0, 3)) {
                int lo = h / 3 - 3;
                for (int c3 : ra(lo, lo + 8)) {
                    // can it be done
                    auto can = [&](int x) {
                        for (int t1 : ra(0, c1 + 1)) {
                            for (int t2 : ra(0, c2 + 1)) {
                                int r = x - t1 - 2*t2;
                                if (r >= 0 && r % 3 == 0 && r / 3 <= c3) {
                                    return true;
                                }
                            }
                        }
                        return false;
                    };

                    if (R::count_if(a, can) == n) {
                        sol = min(sol, c1 + c2 + c3);
                    }
                }
            }
        }

        cout << sol << '\n';
    }
}