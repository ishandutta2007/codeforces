// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct korak {
    ll x, y;
    char op;
};

vector<korak> sol;

ll make_multiple(ll x, ll y) {
    if (y == 1) {
        return x;
    }

    ll z = make_multiple(x, y >> 1);
    sol.push_back({z, z, '+'});
    if (y & 1) {
        sol.push_back({2*z, x, '+'});
    }

    return x*y;
}

void make_big_target(ll x, ll y, ll t) {
    for (ll r=1;; r++) {
        if ((t - x*r) % y == 0) {
            make_multiple(x, r);
            make_multiple(y, (t - x*r) / y);
            sol.push_back({x*r, t-x*r, '+'});
            return;
        }
    }
}

ll make_gcd(ll x, ll y) {
    ll g = gcd(x, y);
    ll t1 = (x*y/g) << 20;
    ll t2 = t1 + g;
    
    make_big_target(x, y, t1);
    make_big_target(x, y, t2);

    sol.push_back({t1, t2, '^'});
    return g;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    ll x;
    cin >> x;

    while (x > 1) {
        for (ll y=x;; y+=x) {
            ll z = y + x;
            ll w = y^z;
            if (w <= 4*x && w % x) {
                make_multiple(x, y/x);
                make_multiple(x, z/x);
                sol.push_back({y, z, '^'});
                x = make_gcd(x, w);
                break;
            }
        }
    }

    cout << sol.size() << '\n';
    for (auto [x, y, op] : sol) {
        cout << x << ' ' << op << ' ' << y << '\n';
    }
}