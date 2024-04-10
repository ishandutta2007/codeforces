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
        int n;
        string s;
        cin >> n >> s;

        vector<int> m, t;

        for (int i=0; i<n; i++) {
            if (s[i] == 'T') {
                t.push_back(i);
            } else {
                m.push_back(i);
            }
        }

        if (m.size() * 2 != t.size()) {
            cout << "NO\n";
            continue;
        }

        bool ok = 1;

        for (int i=0; i<m.size(); i++) {
            if (!(t[i] < m[i] && m[i] < t[i + m.size()])) {
                ok = 0;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}