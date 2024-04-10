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

        vector<array<int, 6>> dat(n);

        ll amb = 0, sl = 0, sr = 0, tgt = 0;

        for (int i : ra(0, n)) {
            int a, b;
            cin >> a >> b;
            dat[i][0] = a;
            dat[i][1] = b;

            int l, r;
            if (m <= a) {
                r = m;
            } else {
                r = a - (m - a);
            }

            if (m <= b) {
                l = m;
            } else {
                l = b - (m - b);
            }
            l *= -1;

            dat[i][2] = l;
            dat[i][3] = r;

            amb += a-b;
            sl += l;
            sr += r;
        }

        if (sl <= amb && amb <= sr) {
            tgt = amb;
            if (tgt % 2 != sl % 2) {
                tgt -= 1;
            }
        } else if (amb < sl) {
            tgt = sl;
        } else {
            tgt = sr;
        }

        ll above = tgt - sl;

        for (int i : ra(0, n)) {
            ll l = dat[i][2];
            ll r = dat[i][3];

            ll d = min(above, r-l);
            above -= d;
            d += l;

            // napravi razliku d
            dat[i][4] = (m+d) / 2;
            dat[i][5] = (m-d) / 2;
        }

        cout << abs(amb - tgt) << '\n';

        for (int i : ra(0, n)) {
            cout << dat[i][4] << ' ' << dat[i][5] << "\n";
        }
    }
}