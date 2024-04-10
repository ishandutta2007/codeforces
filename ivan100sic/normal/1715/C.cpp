// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
int a[100005];
int b[100005];

ll z;

ll f(int i) {
    return (i+1ll) * (n-1-i);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;

    for (int i : ra(0, n)) {
        cin >> a[i];
    }

    auto go = [&](int i, int d) {
        b[i] = a[i] != a[i+1];
        z += d * b[i] * f(i);
    };

    z += n*(n+1ll) / 2;

    for (int i : ra(0, n-1)) {
        go(i, 1);
    }

    while (m--) {
        int i, x;
        cin >> i >> x;
        i--;

        if (i > 0) go(i-1, -1);
        if (i != n-1) go(i, -1);
        a[i] = x;
        if (i > 0) go(i-1, 1);
        if (i != n-1) go(i, 1);
        cout << z << '\n';    
    }
}