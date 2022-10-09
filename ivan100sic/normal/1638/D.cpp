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

    int n, m;
    cin >> n >> m;
    vector a(n, vector(m, 0));
    for (int i : ra(0, n)) {
        for (int j : ra(0, m)) {
            cin >> a[i][j];
        }
    }

    auto eq = [&](int x, int y) {
        return x == y || x == -1 || y == -1;
    };

    vector<array<int, 3>> sol;

    auto touch = [&](int i, int j, auto self) {
        if (i >= n-1 || j >= m-1 || i < 0 || j < 0) return;
        int& p = a[i][j];
        int& q = a[i+1][j];
        int& r = a[i][j+1];
        int& s = a[i+1][j+1];
        int u = max({p, q, r, s});
        if (eq(p, q) && eq(p, r) && eq(p, s) && eq(q, r) && eq(q, s) && eq(r, s) && u > 0) {
            sol.push_back({i, j, max({p, q, r, s})});
            p = q = r = s = -1;
            for (int dx=-1; dx<=1; dx++) {
                for (int dy=-1; dy<=1; dy++) {
                    self(i+dx, j+dy, self);
                }
            }
        }
    };

    for (int i : ra(0, n-1)) {
        for (int j : ra(0, m-1)) {
            touch(i, j, touch);
        }
    }

    if (R::all_of(a, [](auto& r) { return -1 == *R::max_element(r); })) {
        cout << sol.size() << "\n";
        for (auto [x, y, z] : R::reverse_view(sol)) {
            cout << x+1 << ' ' << y+1 << ' ' << z << '\n';
        }
    } else {
        cout << "-1\n";
    }
}