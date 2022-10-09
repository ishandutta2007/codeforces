// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int inf = 1e9 + 7;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector a(m, vector(n, 0));

        for (int i : ra(0, m)) {
            for (int j : ra(0, n)) {
                cin >> a[i][j];
            }
        }

        cout << *R::partition_point(ra(0, inf), [&](int w) {
            vector<int> u(m), v(n);
            for (int i : ra(0, m)) {
                for (int j : ra(0, n)) {
                    if (a[i][j] >= w) {
                        u[i]++;
                        v[j]++;
                    }
                }
            }

            return *R::max_element(u) >= 2 && *R::min_element(v) >= 1;
        }) - 1 << '\n';
    }
}