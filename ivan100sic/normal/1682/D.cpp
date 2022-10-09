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

        int j = R::find(s, '1') - begin(s);
        if (j == n) {
            cout << "NO\n";
            continue;
        }

        if (R::count(s, '1') % 2) {
            cout << "NO\n";
            continue;
        }

        int root = (j+1) % n;
        int attached = -1;

        auto e = [](int x, int y) {
            cout << x+1 << ' ' << y+1 << '\n';
        };

        cout << "YES\n";
        for (int i : ra(1, n)) {
            // j+2 ...
            int x = (i+j+1) % n;
            if (s[x] == '1') {
                if (attached == -1) {
                    e(root, x);
                } else {
                    e(attached, x);
                    attached = -1;
                }
            } else {
                if (attached == -1) {
                    e(root, x);
                } else {
                    e(attached, x);
                }
                attached = x;
            }
        }
    }
}