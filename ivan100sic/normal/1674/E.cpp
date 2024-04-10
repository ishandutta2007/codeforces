// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int h(int x) {
    return (x+1)/2;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    vector<int> a(n);

    for (int& x : a) cin >> x;
    
    int sol = 1e9;

    int run = 1e9;
    for (int i : ra(0, n)) {
        if (i >= 3) {
            run = min(run, a[i-3]);
        }

        sol = min(sol, h(run) + h(a[i]));
    }

    // dst 2
    for (int i : ra(2, n)) {
        int x = a[i-2], y = a[i];

        sol = min(sol, h(x) + h(y));
        sol = min(sol, min(x, y) + h(max(x, y) - min(x, y)));
    }

    // dst 1
    for (int i : ra(1, n)) {
        int x = a[i-1], y = a[i];
        if (x > y) swap(x, y);
        if (y >= 2*x) {
            sol = min(sol, h(y));
        } else {
            int d = y-x;
            int t = x-d;
            sol = min(sol, d + t/3*2 + t%3);
        }
    }

    cout << sol << '\n';
}