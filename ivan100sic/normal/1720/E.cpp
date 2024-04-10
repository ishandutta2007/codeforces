// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, k;
int a[500][500];
int f[250000], uq;

void ad(int x) {
    if (++f[x] == 1) {
        uq++;
    }
}

void rm(int x) {
    if (--f[x] == 0) {
        uq--;
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;
    for (int i : ra(0, n)) {
        for (int j : ra(0, n)) {
            int x;
            cin >> x;
            x--;
            a[i][j] = x;
            ad(x);
        }
    }

    if (k >= uq) {
        cout << k - uq << '\n';
        return 0;
    }

    // 1 or 2
    if (k == 1) {
        cout << "1\n";
        return 0;
    }

    for (int diag : ra(1-n, n)) {
        // diag = y - x
        int x0 = 0;
        int y0 = diag;
        {
            int incr = -min(x0, y0);
            x0 += incr;
            y0 += incr;
        }

        int len = n - abs(diag);

        int r = 0;
        for (int l : ra(0, len)) {
            while (r < len && k < uq) {
                // increase r
                for (int i : ra(0, r-l)) {
                    rm(a[x0+l+i][y0+r]);
                    rm(a[x0+r][y0+l+i]);
                }
                rm(a[x0+r][y0+r]);
                r++;
            }

            // good?
            if (k == uq || k == uq+1) {
                cout << "1\n";
                return 0;
            }

            // increase l (pop)
            {
                for (int i : ra(1, r-l)) {
                    ad(a[x0+l+i][y0+l]);
                    ad(a[x0+l][y0+l+i]);
                }
                ad(a[x0+l][y0+l]);
            }
        }
    }

    cout << "2\n";
}