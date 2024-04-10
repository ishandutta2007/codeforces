// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

/*
0 1 1
1 2 2
1 2 2

Z = 0
All 0s must have the same color, others don't matter
Solvable if there are at most n/2 0s

Z = 1
If there are 0s and non-0s, everything must have the same color
Solvable if there are not 0s (implies Z=0 is solvable)
or all are 0s

Z = 2
All 1s and 2s must have the same color, color of 0s
doesn't matter. Solvable if there are at most n/2 of 1s and 2s combined.
*/

int main() {
    ios::sync_with_stdio(!cin.tie(0));

#ifdef LOCAL
    for (int i : ra(0, 3)) {
        for (int j : ra(0, 3)) {
            int x = (i+j)*(i+j) + i*j;
            x %= 3;

            cerr << x << " \n"[j == 2];
        }
    }
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> e[3];
    for (int i : ra(0, n)) {
        e[a[i] % 3].push_back(i);
    }

    string t(n, '0');
    int z = -1;

    int c0 = 0;
    for (int i : R::join_view(e)) {
        t[i] = (c0++ < n/2) + '0';
    }

    if (ssize(e[0]) <= n/2) {
        z = 0;
    } else {
        z = 2;
    }

    cout << z << '\n';
    if (z != -1) {
        cout << t << '\n';
    }
}