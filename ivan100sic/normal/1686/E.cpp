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

        string s;
        cin >> s;
    
        int z = 0;

        auto v = [&](int i) {
            return s[i] == '(' ? 1 : -1;
        };

        int lz = 0, li = 0, tot = 0;
        for (int i : ra(0, 2*n)) {
            z += v(i);
            if (z < 0) break;
            if (z > lz) {
                lz = z;
                li = i+1;
            }
            tot++;
        }

        if (tot == 2*n) {
            cout << "0\n";
            continue;
        }

        z = 0;
        int rz = 0, ri = 0;
        for (int i : ra(0, 2*n)) {
            z += -v(2*n-1-i);
            if (z < 0) break;
            if (z > rz) {
                rz = z;
                ri = i+1;
            }
        }

        z = 0;
        int hz = 0, hi = 0;
        for (int i : ra(0, 2*n)) {
            z += v(i);
            if (z > hz) {
                hz = z;
                hi = i+1;
            }
        }

        if (hz <= lz + rz) {
            cout << "1\n";
            cout << li+1 << ' ' << 2*n-ri << '\n';
        } else {
            cout << "2\n";
            cout << "1 " << hi << '\n';
            cout << hi+1 << ' ' << 2*n << '\n';
        }
    }
}