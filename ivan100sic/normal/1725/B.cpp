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

    int n, d, sol = 0;
    cin >> n >> d;
    d++;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    R::sort(a, greater<>{});

    int used = 0;
    for (int i : ra(0, n)) {
        int team = (d + a[i] - 1) / a[i];
        
        if (used + team > n) {
            break;
        }

        used += team;
        sol++;
    }

    cout << sol << '\n';
}