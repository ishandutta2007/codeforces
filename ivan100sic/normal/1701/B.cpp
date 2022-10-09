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
        cout << "2\n";
        for (int i : ra(1, n+1)) {
            if (i % 2) {
                for (int j=i; j<=n; j<<=1) {
                    cout << j << ' ';
                }
            }
        }
        cout << '\n';
    }
}