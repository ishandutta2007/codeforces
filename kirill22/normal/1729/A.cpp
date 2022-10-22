#include "bits/stdc++.h"

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b = c - 1 + abs(b - c);
    if (a == b) {
        cout << 3 << '\n';
    } else if (a > b) {
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
    }
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