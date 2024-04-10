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

    vector<string> a(n);
    vector z(n, vector(m, 0));
    for (auto& s : a) cin >> s;

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            z[i+1][j+1] = a[i][j+1] == 'X' && a[i+1][j] == 'X';
            z[i+1][j+1] += z[i][j+1] + z[i+1][j] - z[i][j];
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << (z[n-1][r-1] == z[n-1][l-1] ? "YES\n" : "NO\n");
    }
    
}