// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll fib[105];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    ll n, z = 1;
    cin >> n;

    fib[1] = 1;
    for (int i=2; i<=90; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if (fib[i] <= n) {
            z = i-2;
        }
    }

    cout << z << '\n';
}