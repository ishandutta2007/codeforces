// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

array<int, 3> maxsum(auto b) {
    int low = 0, lowval = 0;
    int l, r, s = 0, z = 0;

    for (int i : ra(0, ssize(b))) {
        if (z < lowval) {
            lowval = z;
            low = i;
        }

        z += b[i];
        if (z - lowval >= s) {
            s = z - lowval;
            l = low;
            r = i+1;
        }
    }

    return {l, r, s};
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        map<int, vector<int>> e;
        for (int i : ra(0, n)) {
            e[a[i]].push_back(i);
        }

        int sol = -1, ksol = -1;
        for (auto [k, v] : e) {
            vector<int> b;
            for (int i : ra(0, ssize(v) - 1)) {
                b.push_back(1);
                b.push_back(v[i] - v[i+1] + 1);
            }
            b.push_back(1);

            {
                auto [l, r, s] = maxsum(b);
                if (s > sol) {
                    sol = s;
                    ksol = k;
                }
            }
        }

        {
            auto [l, r, s] = maxsum(R::transform_view(a, [&](int x) { return x == ksol ? 1 : -1; }));
            cout << ksol << ' ' << l+1 << ' ' << r << '\n';
        }
    }
}