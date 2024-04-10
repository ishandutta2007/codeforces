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

        for (int j : ra(0, m)) {
            for (int rep : ra(0, n)) {
                for (int i : ra(0, n-1)) {
                    if (a[i][j] == '*' && a[i+1][j] == '.') {
                        swap(a[i][j], a[i+1][j]);
                    }
                }
            }
        }

        for (int i : ra(0, n)) cout << a[i] << '\n';
        cout << '\n';
    }
}