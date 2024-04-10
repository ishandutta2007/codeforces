// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int ask(int n, int p, int q) {
    cout << '?';
    for (int i=0; i<n; i++) {
        cout << ' ' << (i == n-1 ? q : p);
    }
    cout << '\n' << flush;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    vector<int> a(n);
    int& last = a[n-1];
    last = 1;
    for (int x=n; x>=2; x--) {
        if (ask(n, n, n+1-x)) {
            last = x;
            break;
        }
    }
    
    for (int x : ra(1, n+1)) {
        if (x == last) continue;

        int u = last - x, v = 0;
        int d = 1-min(u, v);
        u += d;
        v += d;

        int z = ask(n, u, v);
        a[z-1] = x;
    }

    cout << '!';
    for (int x : a) cout << ' ' << x;
    cout << '\n' << flush;
}