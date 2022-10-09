// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

vector<ll> a;

bool solve(ll x, ll y) {
    a.push_back(x);
    if (x == y) {
        cout << "YES\n";
        cout << a.size() << '\n';
        for (ll z : a) {
            cout << z << ' ';
        }
        cout << '\n';
        return true;
    } else if (x < y) {
        if (solve(2*x, y)) return true;
        if (solve(10*x+1, y)) return true;
    }

    a.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    ll x, y;
    cin >> x >> y;

    if (!solve(x, y)) {
        cout << "NO\n";
    }
}