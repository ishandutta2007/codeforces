// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int am[64], an[64];
ll d[64][3][2][2];

ll solve(ll n, ll m) {
    for (int i : ra(0, 62)) {
        am[i] = (m >> i) & 1;
        an[i] = (n >> i) & 1;
    }

    memset(d, 0, sizeof(d));
    d[0][1][0][0] = 1;
    for (int i : ra(0, 62)) {
        for (int e : {0, 1, 2}) {
            for (int c : {0, 1}) {
                for (int p : {0, 1}) {
                    for (int x : {0, 1}) {
                        int s = am[i] + x + c;
                        int dgt = s & 1; 

                        int i2 = i + 1;
                        int e2 = e;
                        if (x < an[i]) {
                            e2 = 0;
                        } else if (x > an[i]) {
                            e2 = 2;
                        }

                        int c2 = s >> 1;
                        int p2 = p ^ dgt ^ x;

                        d[i2][e2][c2][p2] += d[i][e][c][p];
                    }
                }
            }
        }
    }

    return d[62][0][0][1];
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        cout << solve(m, n) << '\n';
    }
}