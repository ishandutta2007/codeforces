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
        vector<pair<int, int>> a(n);
        for (auto& [l, r] : a) {
            cin >> l >> r;
        }

        vector<array<int, 3>> sol;
        vector<int> h(n+1);
        R::fill(span(h).subspan(1), 1);
        // R::fill(span(h).subspan(1), 1);
        // R::fill(begin(h)+1, end(h), 1);
        // it's as long but much sexier
        for (int i : ra(0, n)) {
            vector<int> z(n+1);
            for (int i=1; i<=n; i++) z[i] = z[i-1] + h[i];
            int fl=0, fr=0;
            for (auto [l, r] : a) {
                if (z[r] - z[l-1] == 1) {
                    tie(fl, fr) = tie(l, r);
                }
            }
            a.erase(R::find(a, pair(fl, fr)));
            int x = R::find(begin(h)+fl, begin(h)+fr+1, 1) - begin(h);
            h[x]--;
            sol.push_back({fl, fr, x});
        }
        for (auto [l, r, d] : R::reverse_view(sol)) {
            cout << l << ' ' << r << ' ' << d << '\n';
        }
        cout << '\n';
    }
    
}