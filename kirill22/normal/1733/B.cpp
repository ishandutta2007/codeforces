#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    if (x != 0) {
        cout << -1 << '\n';
        return;
    }
    if (y == 0 || (n - 1) % y != 0) {
        cout << -1 << '\n';
        return;
    }
    int tx = 1, c = y;
    for (int i = 2; i <= n; i++) {
        cout << tx << " ";
        c--;
        if (c == 0) {
            tx = i + 1;
            c = y;
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}