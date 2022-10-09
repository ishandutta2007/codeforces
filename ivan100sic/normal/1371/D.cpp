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

        vector<string> a(n, string(n, '0'));
        cout << 2*!!(k % n) << '\n';
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                a[j][(i+j)%n] = (k-- > 0) + '0';
            }
        }

        for (auto& s : a) cout << s << '\n';
    }
}