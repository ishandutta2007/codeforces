// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int ans(int a, int b, int c) {
    return max(0, max(b, c) + 1 - a);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        cout << ans(a, b, c) << ' ' << ans(b, c, a) << ' ' << ans(c, a, b) << '\n';
    }
}