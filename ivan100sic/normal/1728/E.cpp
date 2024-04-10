// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct dish {
    int a, b;

    strong_ordering operator<=> (const dish& o) const {
        return b-a <=> o.b-o.a;
    }

    bool operator== (const dish& o) const {
        return b-a == o.b-o.a;
    }
};

template<class T>
T eea(T a, T b, T& x, T& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }

    T x1, y1;
    T g = eea(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    vector<dish> a(n);
    for (auto& [a, b] : a) {
        cin >> a >> b;
    }

    R::sort(a);

    // better-a ... better-b
    vector<ll> vals(n+1);
    {
        ll z = 0;
        for (int i : ra(0, n)) {
            z += a[i].a;
            vals[i+1] += z;
        }

        z = 0;
        for (int i : ra(0, n)) {
            z += a[n-1-i].b;
            vals[n-1-i] += z;
        }
    }

    map<array<ll, 3>, ll> cache;

    int q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;

        ll u0, v0;
        ll g = eea(x, y, u0, v0);
        if (n % g) {
            cout << "-1\n";
            continue;
        }

        u0 *= n / g;
        v0 *= n / g;

        ll step = lcm(x, y);

        // x u0 + y v0 = n

        ll above = x*u0 / step;
        ll base = x*u0 - above * step;
        if (base < 0) base += step;

        ll len = (n - base) / step;

        if (base > n) {
            cout << "-1\n";
            continue;
        }

        // cout << "take: " << base << ' ' << step << ' ' << len << '\n';
        // brute:
        auto it = cache.lower_bound({base, step, len});
        if (it != cache.end() && it->first == array{base, step, len}) {
            cout << it->second << '\n';
        } else {
            ll sol = 0;
            for (ll i : ra(0, len+1)) {
                sol = max(sol, vals[base + step * i]);
            }
            cout << sol << '\n';
            cache.emplace_hint(it, array{base, step, len}, sol);
        }
    }
}