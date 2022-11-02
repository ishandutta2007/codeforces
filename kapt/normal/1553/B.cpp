#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        bool ans = false;
        for (int i = 0; i < m && !ans; ++i) {
            bool f = true;
            for (int j = 1; j <= i && j + i < m; ++j) {
                if (t[i - j] != t[i + j]) {
                    f = false;
                    break;
                }
            }
            if (!f) continue;
            string r;
            if (i * 2 >= m) {
                for (int j = 0; j <= i; ++j) {
                    r.push_back(t[j]);
                }
            } else {
                for (int j = m - 1; j >= i; --j) {
                    r.push_back(t[j]);
                }
            }
            int k = r.size();
            if (k > n) continue;
            for (int j = 0; j < n - k + 1; ++j) {
                bool f = true;
                for (int p = 0; p < k; ++p) {
                    if (r[p] != s[j + p]) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    ans = true;
                    break;
                }
            }
        }
        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}