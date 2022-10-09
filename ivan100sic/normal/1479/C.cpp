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

    int l, r;
    cin >> l >> r;

    vector<array<int, 3>> roads;

    // construct the "engine"
    const int slack = 8;

    for (int i=0; i<20; i++) {
        int x = 31-i;
        for (int y=x+1; y<=32; y++) {
            int w = y == 32 ? 1 : 1 << (31-y);
            roads.push_back({x, y, w});
        }
    }

    if (l == 1) {
        roads.push_back({1, 32, 1});
        l++;
    }

    while (l <= r) {
        int i = 0;
        while ((1 << (i+1)) <= (r-l+1)) {
            i++;
        }

        roads.push_back({1, 31-i, l-1});
        l += 1 << i;
    }

    cout << "YES\n 32 " << roads.size() << '\n';
    for (auto [a, b, c] : roads) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}