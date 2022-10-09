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
        string a, b;
        cin >> n >> a >> b;
        int r = 0, s = 0, ok = 1;
        for (int i=0; i<n; i++) {
            s += a[i] == '0' ? 1 : -1;
            if (s == 0) {
                int c = 0;
                for (int j=r; j<=i; j++) {
                    c += a[j] == b[j];
                }
                if (c != 0 && c != i-r+1) {
                    ok = 0;
                    break;
                }
                r = i+1;
            }
        }

        int c = 0;
        for (int j=r; j<n; j++) {
            c += a[j] == b[j];
        }

        if (c != n-r) {
            ok = 0;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}