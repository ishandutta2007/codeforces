// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct thing {
    ll x, c;

    thing() : x(-1), c(0) {}
    thing(ll x) : x(x), c(1) {}
    thing(ll x, ll c) : x(x), c(c) {}

    thing operator+ (const thing& b) const {
        if (x == b.x) return {x, c + b.c};
        else if (x > b.x) return *this;
        else return b;
    }

    thing& operator+= (const thing& b) {
        return *this = *this + b;
    }
};

int n, m, r;
int a[505][505];
int reach[1005], offset[1005];
int z[505][505], b[505][505];

thing pref[505][505], suff[505][505];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> r;
    for (int i : ra(0, n)) {
        for (int j : ra(0, m)) {
            cin >> a[i][j];
        }
    }

    // reach[x] = min y s.t. (x, y) is not in circle at (0, 0)
    for (int x : ra(0, 501)) {
        int& y = reach[x];
        while (x*x + y*y <= r*r) {
            y++;
        }
        if (x > r) {
            y = -123123123;
        }
    }

    // offset[x] = min y s.t. (x, y) and (0, 0) circle do not intersect
    for (int x : ra(0, 2*r+1)) {
        auto isec = [&](int x, int y) {
            for (int i=0; i<=x; i++) {
                if (reach[i] + reach[x-i] > y + 1) {
                    return true;
                }
            }
            return false;
        };

        int& y = offset[x];
        while (isec(x, y)) y++;
    }

    for (int i : ra(0, n)) {
        for (int j : ra(0, m)) {
            z[i][j+1] = z[i][j] + a[i][j];
        }
    }

    if (2*r+1 > n || 2*r+1 > m) {
        cout << "0 0\n";
        return 0;
    }

    for (int i : ra(r, n-r)) {
        for (int j : ra(r, m-r)) {
            int sum = 0;
            for (int f : ra(-r, r+1)) {
                int w = reach[abs(f)] - 1;
                sum += z[i+f][j+w+1] - z[i+f][j-w];
            }

            b[i][j] = sum;
        }
    }

    for (int i : ra(0, n)) {
        for (int j : ra(0, m)) {
            pref[i][j+1] = pref[i][j] + thing(b[i][j]);
            suff[i][j+1] = suff[i][j] + thing(b[i][m-j-1]);
        }
    }

    thing sol;
    for (int i : ra(r, n-r)) {
        for (int j : ra(r, m-r)) {

            thing me;
            for (int t : ra(r, n-r)) {
                if (abs(t-i) > 2*r) {
                    // take all
                    me += pref[t][m];
                } else {
                    int pr = j+1;
                    int su = m-j;
                    int w = offset[abs(t-i)];

                    pr = max(0, pr - w);
                    su = max(0, su - w);

                    me += pref[t][pr] + suff[t][su];
                }
            }

            if (me.c > 0 && me.x > 0) {
                me.x += b[i][j];
                sol += me;
            }
        }
    }

    if (sol.x > 0) {
        cout << sol.x << ' ' << sol.c / 2 << '\n';
    } else {
        cout << "0 0\n";
    }
}