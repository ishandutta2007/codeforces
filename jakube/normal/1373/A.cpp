#include "bits/stdc++.h"
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < c)
        cout << 1;
    else
        cout << -1;
    cout << " ";
    if (a * (long long) b > c)
        cout << b;
    else
        cout << -1;
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}