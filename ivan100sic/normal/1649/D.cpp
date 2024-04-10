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
        int n, c;
        cin >> n >> c;
        vector<int> a(c+1);
        bool has2 = 0;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            if (a[x]) {
                has2 = 1;
            } else {
                a[x] = 1;
            }
        }

        if (has2) {
            if (!a[1]) {
                cout << "No\n";
                continue;
            }
        }

        vector<int> z(c+2);
        partial_sum(a.begin(), a.end(), z.begin() + 1);

        // u / v = q
        bool f = 0;
        for (int v : ra(1, c+1)) {
            for (int q : ra(1, c+1)) {
                int ul = v*q;
                int ur = v*q+v;
                if (ul > c+1) break;
                if (z[min(ur, c+1)] != z[min(ul, c+1)] && a[v] && !a[q]) {
                    f = 1;
                    break;
                }
            }
        }

        cout << (f ? "No\n" : "Yes\n");
    }
}