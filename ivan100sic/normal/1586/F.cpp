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

    int n, k;
    cin >> n >> k;

    int w = k, c = 1;
    while (w < n) {
        w *= k;
        c++;
    }

    cout << c << '\n';
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int x = i, y = j, z = 0;
            while (x != y) {
                x /= k;
                y /= k;
                z++;
            }
            cout << z << ' ';
        }
    }
    cout << "\n";
}