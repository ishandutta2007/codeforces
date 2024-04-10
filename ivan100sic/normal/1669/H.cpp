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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        for (int i=30; i>=0; i--) {
            vector<int> bl;
            for (int idx : ra(0, n)) {
                int x = a[idx];
                if (!(x & (1 << i))) {
                    bl.push_back(idx);
                }
            }
            if (ssize(bl) <= k) {
                for (int idx : bl) {
                    a[idx] |= 1 << i;
                }
                k -= ssize(bl);
            }
        }

        cout << accumulate(begin(a), end(a), ~0, bit_and<int>{}) << '\n';
    }
}