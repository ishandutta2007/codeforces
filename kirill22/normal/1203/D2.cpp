#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> a(m), b(m);
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (x < m && s[i] == t[x]) {
            a[x] = i;
            x++;
        }
    }
    x = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (x >= 0 && s[i] == t[x]) {
            b[x] = i;
            x--;
        }
    }
    int L = 0, R = n + 1;
    while (L + 1 < R) {
        int mi = (L + R) / 2;
        bool f = false;
        if (b[0] >= mi) {
            f = true;
        }
        if (n - a[m - 1] - 1 >= mi) {
            f = true;
        }
        for (int i = 0; i < m - 1; i++) {
            if (b[i + 1] - a[i] - 1 >= mi) {
                f = true;
            }
        }
        if (f) {
            L = mi;
        }
        else {
            R = mi;
        }
    }
    cout << L;
}