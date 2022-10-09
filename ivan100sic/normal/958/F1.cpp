// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m, a[105], f[105], f2[105];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i : ra(0, n)) cin >> a[i];
    for (int i : ra(1, m+1)) cin >> f[i];

    int tot = accumulate(f+1, f+m+1, 0);

    for (int i : ra(0, n-tot+1)) {
        memset(f2, 0, sizeof(f2));
        for (int j : ra(i, i+tot)) {
            f2[a[j]]++;
        }
        if (equal(f2+1, f2+m+1, f+1)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}