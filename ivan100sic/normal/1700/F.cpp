// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int a[2][200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    int sum = 0;
    for (int d : {1, -1}) {
        for (int i : ra(0, 2)) {
            for (int j : ra(0, n)) {
                int x;
                cin >> x;
                a[i][j] += x * d;
                sum += x * d;
            }
        }
    }

    if (sum != 0) {
        cout << "-1\n";
        return 0;
    }

    int x = 0, y = 0;
    ll sol = 0;

    for (int i : ra(0, n)) {
        int& x = a[0][i];
        int& y = a[1][i];

        if (x > 0 && y < 0) {
            int d = min(x, -y);
            x -= d;
            y += d;
            sol += d;
        }

        if (x < 0 && y > 0) {
            int d = min(y, -x);
            y -= d;
            x += d;
            sol += d;
        }

        a[0][i+1] += x;
        sol += abs(x);

        a[1][i+1] += y;
        sol += abs(y);

        x = y = 0;
    }

    cout << sol << '\n';
}