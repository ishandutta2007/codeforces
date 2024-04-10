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
        vector<int> a(n), sol(n, 1e9);
        for (int& x : a) cin >> x, x--;

        vector<int> inc = {0}, dec = {0};
        sol[0] = 0;

        for (int i : ra(1, n)) {
            while (dec.size() && a[i] > a[dec.back()]) {
                dec.pop_back();
            }

            while (inc.size() && a[i] < a[inc.back()]) {
                inc.pop_back();
            }

            // both dirs
            int b = inc.size() ? inc.back() : -1;
            auto it = R::lower_bound(dec, b);
            if (it != dec.end()) {
                sol[i] = min(sol[i], sol[*it] + 1);
            }

            b = dec.size() ? dec.back() : -1;
            it = R::lower_bound(inc, b);
            if (it != inc.end()) {
                sol[i] = min(sol[i], sol[*it] + 1);
            }

            dec.push_back(i);
            inc.push_back(i);
        }

        cout << sol[n-1] << '\n';
    }
}