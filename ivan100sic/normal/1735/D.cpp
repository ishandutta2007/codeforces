// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const ll w[3] = {0, 1, 2};

int n, k;

ll add(ll x, ll y) {
    x += y;
    for (int i : ra(0, k)) {
        if ((x & (4ll << 3*i)) || (x & (3ll << 3*i)) == (3ll << 3*i)) {
            x -= 3ll << 3*i;
        }
    }
    return x;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;

    vector<ll> a(n);
    for (int i : ra(0, n)) {
        ll y = 0;
        for (int i : ra(0, k)) {
            int x;
            cin >> x;
            y += ll(x) << (3*i);
        }
        a[i] = y;
    }

    R::sort(a);

    map<ll, int> cnt;
    for (int i : ra(0, n)) {
        for (int j : ra(0, i)) {
            cnt[add(a[i], a[j])]++;
        }
    }

    ll sol = 0;
    for (auto [k, v] : cnt) {
        if (v >= 2) {
            sol += R::equal_range(a, add(k, k)).size() * v * (v-1) / 2;
        }
    }

    cout << sol << '\n';
}