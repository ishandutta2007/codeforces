// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct pt {
    int x, y;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    vector<pt> e, o;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ((i+j) & 1 ? e : o).push_back({i, j});
        }
    }

    auto put = [&](vector<pt>& o, int c) {
        auto [x, y] = o.back();
        o.pop_back();
        cout << c << ' ' << x << ' ' << y << '\n' << flush;
    };

    for (int i=0; i<n*n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            if (o.size()) {
                put(o, 2);
            } else {
                put(e, 3);
            }
        } else if (t == 2) {
            if (e.size()) {
                put(e, 1);
            } else {
                put(o, 3);
            }
        } else {
            if (e.size()) {
                put(e, 1);
            } else {
                put(o, 2);
            }
        }
    }
}