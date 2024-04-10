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

        int lvl = 2;
        if (R::count_if(a, [&](auto& s) { return R::count(s, '0') > 0; })) {
            lvl = 1;
        }

        for (int i : ra(0, n)) {
            for (int j : ra(0, m-1)) {
                if (a[i][j] == '0' && a[i][j+1] == '0') {
                    lvl = 0;
                }
            }
        }

        for (int i : ra(0, n-1)) {
            for (int j : ra(0, m)) {
                if (a[i][j] == '0' && a[i+1][j] == '0') {
                    lvl = 0;
                }
            }
        }

        for (int i : ra(0, n-1)) {
            for (int j : ra(0, m-1)) {
                if (a[i][j+1] == '0' && a[i+1][j] == '0') {
                    lvl = 0;
                }

                if (a[i+1][j+1] == '0' && a[i][j] == '0') {
                    lvl = 0;
                }
            }
        }

        int cnt1 = 0;
        for (auto& s : a) {
            cnt1 += R::count(s, '1');
        }

        cout << cnt1 - lvl << '\n';
    }
}