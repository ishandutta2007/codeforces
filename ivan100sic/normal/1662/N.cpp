// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[1505][1505];
int sc[1505][1505], sr[1505][1505];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) {
        for (int j : ra(0, n)) {
            cin >> a[i][j];
            sr[i][j] = a[i][j];
            sc[j][i] = a[i][j];
        }
    }

    for (int i : ra(0, n)) {
        sort(sc[i], sc[i] + n);
        sort(sr[i], sr[i] + n);
    }

    ll sol = 0;

    for (int i : ra(0, n)) {
        for (int j : ra(0, n)) {
            int x = a[i][j];
            int r = lower_bound(sr[i], sr[i] + n, x) - sr[i];
            int c = lower_bound(sc[j], sc[j] + n, x) - sc[j];

            sol += r*c + (n-r-1)*(n-c-1);
        }
    }

    ll q = n*(n-1ll)*n*(n-1ll)/4;

    cout << q-(sol - 2*q)/2 << '\n';
}