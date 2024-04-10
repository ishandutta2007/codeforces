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

    int n, m;
    cin >> n >> m;
    
    vector<ll> c(100005, 0), d;
    vector a(n, vector(m, 0));

    for (int i : ra(0, n)) {
        for (int j : ra(0, m)) {
            int x;
            cin >> x;
            c[x]++;
            a[i][j] = x;
        }
    }

    ll sol = 0, sum = 0;
    d = c;
    for (int i : ra(0, n)) {
        for (int j : ra(0, m)) {
            int x = a[i][j];
            sum -= d[x]*(c[x] - d[x]);
            d[x]--;
            sum += d[x]*(c[x] - d[x]);
        }
        sol += sum;
    }

    d = c;
    for (int j : ra(0, m)) {
        for (int i : ra(0, n)) {
            int x = a[i][j];
            sum -= d[x]*(c[x] - d[x]);
            d[x]--;
            sum += d[x]*(c[x] - d[x]);
        }
        sol += sum;
    }

    cout << sol << '\n';
}