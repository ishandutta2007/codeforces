// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> e(m);
        for (auto& [x, y, z] : e) {
            cin >> x >> y >> z;
            x--, y--;
        }

        auto conn = [&](auto cond) {
            union_find uf(n);
            int c = 0;
            for (auto [x, y, z] : e) {
                if (cond(z)) {
                    c += uf.join(x, y);
                }
            }
            return c == n-1;
        };

        int sofar = 0;
        for (int b=29; b>=0; b--) {
            // can we take all less than b and those more in mask
            if (!conn([&](int x) { return (x & (sofar + (1 << b) - 1)) == x; })) {
                sofar += 1 << b;
            }
        }
        cout << sofar << '\n';
    }
}