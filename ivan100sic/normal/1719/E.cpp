// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int fib[43];

void mkfib() {
    fib[0] = 1;
    fib[1] = 2;
    for (int i : ra(2, ssize(fib))) {
        fib[i] = fib[i-2] + fib[i-1];
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    mkfib();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int& x : c) cin >> x;

        vector<ull> w(n), w1(n);
        bool bad = 0;

        auto ways = [&](int x) {
            ull w = 0;
            for (int i=ssize(fib)-1; i>=0; i--) {
                if (fib[i] <= x) {
                    w |= 1ull << i;
                    x -= fib[i];
                }
            }
            return w;
        };

        for (int i : ra(0, n)) {
            w[i] = ways(c[i]);
            w1[i] = ways(c[i] - 1);
        }

        bool found = 0;

        // no need for 1 donator?
        if (n == 1 && c[0] == 1) {
            // First time I remember using this crap in CP (or ever)
            goto f_end;
        }

        for (int i : ra(0, n)) {
            if (w1[i] & 1) {
                continue;
            }

            bool ok = 1;

            // Take all
            ull m = w1[i];
            for (int j : ra(0, n)) {
                if (j != i) {
                    if (m & w[j]) {
                        ok = 0;
                    }
                    m |= w[j];
                }
            }

            if (m & (m+1)) {
                ok = 0;
            }

            if (ok) {
                found = 1;
                break;
            }
        }

        if (!found) {
            bad = 1;
        }

    f_end:
        cout << (bad ? "NO\n" : "YES\n");
    }
}