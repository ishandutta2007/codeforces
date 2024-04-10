// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int a[350];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    for (int i : ra(0, n)) {
        cin >> a[i];
    }

    for (int x : ra(0, n)) {
        int d = a[x] - x*x + n*n; 
        for (int y : ra(0, n)) {
            cout << (x*y + d + n*n) % n << " \n"[y == n-1];
        }
    }
}