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
        vector<int> a(n), b(n), d(n);
        for (int i : ra(0, n)) cin >> a[i], a[i]--;
        for (int i : ra(0, n)) cin >> b[i], b[i]--;
        for (int i : ra(0, n)) cin >> d[i], d[i]--;

        vector<int> f(n), g(n);
        for (int i : ra(0, n)) {
            f[a[i]] = b[i];
            g[a[i]] = d[i] != -1;
        }

        vector<int> vis(n);
        int sol = 1;
        for (int i : ra(0, n)) {
            if (!vis[i]) {
                int seen = 0;
                for (int j=i; !vis[j]; j=f[j]) {
                    vis[j] = 1;
                    if (g[j]) seen = 1;
                }
                if (!seen && f[i] != i) {
                    sol = 2*sol % 1'000'000'007;
                }
            }
        }

        cout << sol << '\n';
    }
}