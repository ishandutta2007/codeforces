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
        vector<string> a(n);
        for (auto& s : a) cin >> s;

        if (a[0][0] == '1') {
            cout << "-1\n";
            continue;
        }

        vector<array<int, 4>> sol;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                if (a[i][j] == '0') {
                    sol.push_back({i, j, i, j});
                } else {
                    if (i > 0) {
                        sol.push_back({i-1, j, i, j});
                    } else {
                        sol.push_back({i, j-1, i, j});
                    }
                }
            }
        }
        
        cout << size(sol) << '\n';
        for (auto [a, b, c, d] : sol | R::views::reverse) {
            cout << a+1 << ' ' << b+1 << ' ' << c+1 << ' ' << d+1 << '\n';
        }
    }
}