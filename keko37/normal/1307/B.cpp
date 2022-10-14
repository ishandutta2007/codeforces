#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t, n, x;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int mx = 0, naso = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a == x) naso = 1;
            mx = max(mx, a);
        }
        if (naso) {
            cout << 1 << '\n';
        } else if (mx < x) {
            cout << (x + mx - 1) / mx << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}