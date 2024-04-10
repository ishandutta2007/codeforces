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
        ll n, m, k;
        cin >> n >> m >> k;

        ll up = (n + m - 1) / m;
        ll dn = n / m;

        ll cnt_up = n % m;
        ll cnt_dn = m - cnt_up;

        ll start = 0, run = 0;

        auto go = [&]() {
            ll r = run++;
            if (run == n) run = 0;
            return r + 1;
        };

        for (int i : ra(0, k)) {
            run = start;
            for (int j : ra(0, cnt_up)) {
                cout << up;
                for (int k : ra(0, up)) {
                    cout << ' ' << go();
                }
                cout << '\n';
            }

            for (int j : ra(0, cnt_dn)) {
                cout << dn;
                for (int k : ra(0, dn)) {
                    cout << ' ' << go();
                }
                cout << '\n';
            }

            start = (start + up * cnt_up) % n;
        }

        cout << '\n';
    }
}