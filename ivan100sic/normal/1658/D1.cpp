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
        int l, r;
        cin >> l >> r;
        int m = r-l+1;

        vector<int> a(m);
        for (int& x : a) cin >> x;
        sort(a.begin(), a.end());
        
        int p=2;
        for (; m%p == 0; p*=2) {
            for (int& x : a) {
                x >>= 1;
            }
            sort(a.begin(), a.end());
            a.erase(unique(a.begin(), a.end()), a.end());
        }

        p /= 2;
        int z = accumulate(begin(a), end(a), 0, bit_xor<int>{});
        for (int i : ra(0, m/p)) z ^= i;
        cout << z * p << '\n';
    }
}