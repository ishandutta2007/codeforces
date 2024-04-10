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

    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;

        map<ll, ll> mp;
        for (int i : ra(0, n)) {
            ll y;
            cin >> y;
            mp[y]++;
        }

        auto nit = mp.begin();
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            while (nit != mp.end() && nit->first < it->first * x) {
                ++nit;
            }

            if (nit != mp.end() && nit->first == it->first * x) {
                ll d = min(nit->second, it->second);
                nit->second -= d;
                it->second -= d;
            }
        }

        ll z = 0;
        for (auto& [k, v] : mp) {
            z += v;
        }

        cout << z << '\n';
    }
}