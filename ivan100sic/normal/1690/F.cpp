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
        string s;
        cin >> n >> s;

        vector<int> p(n), vis(n);
        for (int& x : p) cin >> x, x--;

        ll sol = 1;
        for (int i : ra(0, n)) {
            if (!vis[i]) {
                string t;
                for (int j=i; !vis[j]; j=p[j]) {
                    t += s[j];
                    vis[j] = 1;
                }
                
                auto r = t;
                for (int l=1;; l++) {
                    rotate(r.begin(), r.begin() + 1, r.end());
                    if (r == t) {
                        sol = lcm(sol, l);
                        break;
                    }
                }
            }
        }

        cout << sol << '\n';
    }
}