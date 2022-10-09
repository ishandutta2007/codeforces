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
        int n, s;
        cin >> n >> s;
        vector<int> z(n+1);
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            z[i+1] = z[i] + x;
        }

        vector<int> pos(n+1, -1);
        int sol = -1;
        for (int i : ra(0, n+1)) {
            int x = z[i];
            if (pos[x] == -1) {
                pos[x] = i;
            }

            if (x >= s && pos[x-s] != -1) {
                sol = max(sol, i - pos[x-s]);
            }
        }
        if (sol == -1) {
            cout << -1 << '\n';
        } else {
            cout << n-sol << '\n';
        }
    }
}