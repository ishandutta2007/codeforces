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
        string s;
        cin >> s;
        const int n = ssize(s);

        vector w(n+1, vector(n+1, 0)); // can A win? -1 no

        for (int l=n; l>=0; l--) {
            for (int r=l+2; r<=n; r+=2) {
                int wa = -1;
                for (int la : {0, 1}) {
                    int wb = -1;
                    for (int lb : {0, 1}) {
                        int l2 = l;
                        int r2 = r;
                        char xa = s[la ? l2++ : --r2];
                        char xb = s[lb ? l2++ : --r2];

                        if (w[l2][r2] == 0) {
                            if (xb < xa) {
                                wb = 1;
                            } else if (xb == xa) {
                                wb = max(wb, 0);
                            }
                        } else {
                            wb = max(wb, -w[l2][r2]);
                        }
                    }

                    wa = max(wa, -wb);
                }
                w[l][r] = wa;
            }
        }

        int z = w[0][n];
        if (z == 1) {
            cout << "Alice\n";
        } else if (z == 0) {
            cout << "Draw\n";
        } else {
            cout << "Bob\n";
        }
    }
}