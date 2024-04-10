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

        vector<int> a(m);
        for (int& x : a) cin >> x;

        R::sort(a);

        vector<int> g;
        for (int i : ra(0, m)) {
            int r = a[(i+1)%m];
            int l = a[i];
            if (i == m-1) r += n;

            if (r-l > 1) {
                g.push_back(r-l-1);
            }
        }

        R::sort(g, greater<>{});
        ll sol = 0;
        int loss = 0;
        for (int i : ra(0, ssize(g))) {
            if (g[i] == loss + 1) {
                sol += 1;
                loss += 2;
            } else {
                sol += max(0, g[i] - loss - 1);
                loss += 4;
            }
        }
        cout << n-sol << '\n';
    }
    
}