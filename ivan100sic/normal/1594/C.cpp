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
        char c;
        string s;
        cin >> n >> c >> s;

        if ((int)count(begin(s), end(s), c) == n) {
            cout << "0\n";
            continue;
        }

        bool found = false;
        for (int x=1; x<=n; x++) {
            bool ok = true;
            for (int i=x-1; i<n; i+=x) {
                if (s[i] != c) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << "1\n" << x << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "2\n" << n << ' ' << n-1 << '\n';
        }
    }
}