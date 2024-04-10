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
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int& x : a) cin >> x;

        int k;
        cin >> k;
        vector<int> b(k);
        for (int& x : b) cin >> x;

        auto go = [&](vector<int> a) {
            vector<pair<ll, ll>> b;
            for (int x : a) {
                ll cnt = 1;
                while (x % m == 0) {
                    cnt *= m;
                    x /= m;
                }

                if (b.size() && b.back().first == x) {
                    b.back().second += cnt;
                } else {
                    b.emplace_back(x, cnt);
                }
            }
            return b;
        };

        cout << (go(a) == go(b) ? "YES\n" : "NO\n");
    }
}