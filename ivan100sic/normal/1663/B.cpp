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

    int x, y = -1;
    cin >> x;
    
    vector<int> a = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};

    for (int aa : R::reverse_view(a)) {
        if (x < aa) {
            y = aa;
        }
    }

    cout << y << '\n';
}