#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> d(n);
    d[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != a[i + 1]) {
            d[i] = i + 1;
        } else {
            d[i] = d[i + 1];
        }
    }

    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        if (a[l] != x) {
            cout << l + 1 << '\n';
        } else if (d[l] <= r) {
            cout << d[l] + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}