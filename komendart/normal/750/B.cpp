#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int dy = 0;
    for (int i = 0; i < n; ++i) {
        int d; string s;
        cin >> d >> s;
        if (s[0] == 'S') {
            dy += d;
        } else if (s[0] == 'N') {
            dy -= d;
        } else if (dy == 0 || dy == 20000) {
            cout << "NO\n";
            return 0;
        }
        if (dy < 0 || dy > 20000) {
            cout << "NO\n";
            return 0;
        }
    }
    if (dy == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}