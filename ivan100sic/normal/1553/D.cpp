// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int p = (s.size() + t.size()) % 2;
        int j = p, ok = 1;
        for (char c : t) {
            while (j < (int)s.size() && s[j] != c) {
                j += 2;
            }

            if (j < (int)s.size()) {
                j++;
            } else {
                ok = 0;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}