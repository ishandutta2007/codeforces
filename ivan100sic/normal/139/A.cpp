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

    int s;
    cin >> s;
    int a[7];
    for (int& x : a) cin >> x;

    int i = 0;
    while (1) {
        s -= a[i % 7];
        if (s <= 0) {
            cout << i%7 + 1 << '\n';
            return 0;
        } else {
            i++;
        }
    }
}