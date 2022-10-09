// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

#include <bit>

int par(unsigned x) {
    return bit_ceil(x) - x;
}

struct ret {
    int d, i;
    int v, x, y;

    ret operator+ (const ret& b) const {
        ret z;
        if (d > b.d) {
            z.d = d;
            z.i = i;
        } else {
            z.d = b.d;
            z.i = b.i;
        }

        if (v > b.v) {
            z.v = v;
            z.x = x;
            z.y = y;
        } else {
            z.v = b.v;
            z.x = b.x;
            z.y = b.y;
        }

        return z;
    }

    ret operator* (const ret& b) const {
        ret z = (*this) + b;

        if (d + b.d > z.v) {
            z.v = d + b.d;
            z.x = i;
            z.y = b.i;
        }

        return z;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i : ra(0, n)) {
        int x;
        cin >> x;
        a[i] = x;
        b.push_back(x);
        while (x > 0) {
            x = par(x);
            b.push_back(x);
        }
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    vector<vector<int>> e(b.size());
    for (int i : ra(1, ssize(b))) {
        int p = R::lower_bound(b, par(b[i])) - begin(b);
        e[p].push_back(i);
    }

    vector<char> good(b.size(), 0);
    for (int x : a) {
        int i = R::lower_bound(b, x) - begin(b);
        good[i] = 1;
    }

    auto dfs = [&](int x, auto self) -> ret {
        ret z = {-1, -1, -1, -1, -1};
        int c = 0;
        for (int y : e[x]) {
            auto r = self(y, self);
            // extend
            if (r.d != -1) r.d += 1;
            // add
            if (!c) {
                c = 1;
                z = r;
            } else {
                z = z * r;
            }
        }
        
        if (good[x]) {
            if (z.d == -1) {
                z.d = 0;
                z.i = x;
            } else {
                if (z.d > z.v) {
                    z.v = z.d;
                    z.x = z.i;
                    z.y = x;
                }
            }
        }

        return z;
    };

    auto sol = dfs(0, dfs);
    int u = R::find(a, b[sol.x]) - begin(a) + 1;
    int v = R::find(a, b[sol.y]) - begin(a) + 1;
    cout << u << ' ' << v << ' ' << sol.v << '\n';
}