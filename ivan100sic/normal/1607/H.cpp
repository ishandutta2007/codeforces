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
        int n;
        cin >> n;
        vector<array<int, 4>> dat(n);
        map<int, vector<tuple<int, int, int>>> e;
        for (int i : ra(0, n)) {
            int a, b, m;
            cin >> a >> b >> m;
            dat[i] = {a, b, m, -1};
            int l = max(0, a-m), r = max(0, b-m);
            r = a+b-m-r;
            e[a+b-m].emplace_back(l, r, i);
        }

        int bad = 0;
        for (auto [k, v] : e) {
            set<tuple<int, int, int>> rp, lp;
            for (auto [l, r, i] : v) {
                rp.emplace(r, l, i);
                lp.emplace(l, r, i);
            }

            while (rp.size()) {
                int t = get<0>(*rp.begin());
                bad++;
                while (lp.size()) {
                    auto [l, r, id] = *lp.begin();
                    if (l <= t) {
                        dat[id][3] = t;
                        rp.erase({r, l, id});
                        lp.erase(lp.begin());
                    } else {
                        break;
                    }
                }
            }
        }

        cout << bad << '\n';
        for (auto [a, b, m, sol] : dat) {
            cout << a-sol << ' ' << m-(a-sol) << '\n';
        }
    }
    
}