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

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    int b = 0, bt = -2;

    ll z = 0;
    for (int i : ra(0, n)) {
        int x;
        cin >> x;
        a[i] = {x, -1};
        z += x;
    }

    for (int qi : ra(0, q)) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            int old = a[i].second < bt ? b : a[i].first;
            z -= old;
            z += x;
            a[i] = {x, qi};
        } else {
            int x;
            cin >> x;
            b = x;
            bt = qi;
            z = 1ll*n*x;
        }
        cout << z << '\n';
    }    
}