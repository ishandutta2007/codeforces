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
        string a[8];
        for (auto& b : a) cin >> b;

        for (int i : ra(1, 7)) {
            for (int j : ra(1, 7)) {
                int c = a[i][j] == '#';
                c += a[i-1][j-1] == '#';
                c += a[i+1][j-1] == '#';
                c += a[i-1][j+1] == '#';
                c += a[i+1][j+1] == '#';
                if (c == 5) {
                    cout << i+1 << ' ' << j+1 << '\n';
                }
            }
        }
    }
}