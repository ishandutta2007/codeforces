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
        int n, b = 0;
        cin >> n;

        vector<int> f(n+1), a(n);
        for (int i : ra(0, n)) {
            cin >> a[i];
            f[a[i]]++;
            if (f[a[i]] == 2) {
                b++;
            }
        }

        int i = 0;
        while (b > 0) {
            f[a[i]]--;
            if (f[a[i]] == 1) {
                b--;
            }
            i++;
        }

        cout << i << '\n';
    }
}