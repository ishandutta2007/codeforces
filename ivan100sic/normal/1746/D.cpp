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
        int n, k;
        cin >> n >> k;

        map<pair<int, int>, ll> dp;

        vector<vector<int>> e(n);
        for (int i : ra(1, n)) {
            int p;
            cin >> p;
            p--;
            e[p].push_back(i);
        }

        vector<int> s(n);
        for (int& x : s) cin >> x;

        auto solve = [&](int x, int k, auto self) {
            auto it = dp.lower_bound({x, k});
            if (it != dp.end() && it->first == pair(x, k)) {
                return it->second;
            }

            it = dp.emplace_hint(it, pair(x, k), 0ll);
            ll& sol = it->second;

            sol = 1ll * k * s[x];
            if (e[x].empty()) {
                return sol;
            }

            int m = ssize(e[x]);

            if (k % m == 0) {
                for (int y : e[x]) {
                    sol += self(y, k/m, self);
                }
                return sol;
            }
            
            // split
            vector<pair<ll, ll>> ch;
            for (int y : e[x]) {
                ll lo = self(y, k/m, self);
                ll hi = self(y, k/m+1, self);
                ch.push_back({lo, hi});
            }

            // sort by lo-hi
            R::sort(ch, [](auto p, auto q) { return p.first - p.second < q.first - q.second; });
            // array stars with good hi

            for (int i : ra(0, m)) {
                sol += i < k%m ? ch[i].second : ch[i].first;
            }
            return sol;

        };

        cout << solve(0, k, solve) << '\n';
    }
}