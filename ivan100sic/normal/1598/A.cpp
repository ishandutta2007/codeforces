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
        string a, b;
        cin >> n >> a >> b;

        string ans = "YES\n";
        for (int i : ra(0, n)) {
            if (a[i] == '1' && b[i] == '1') {
                ans = "NO\n";
            }
        }

        cout << ans;
    }
}