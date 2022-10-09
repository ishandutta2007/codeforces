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

        int x=123123, y=123123;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                if (a[i][j] == 'R') {
                    x = min(x, i);
                    y = min(y, j);
                }
            }
        }

        if (a[x][y] == 'R') {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}