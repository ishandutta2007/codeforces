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
        int c = count(begin(s), end(s), '0');
        if (s[0] == '0' || s[n-1] == '0' || n % 2 || c % 2) {
            cout << "NO\n";
            continue;
        }

        string p(n, 0), q(n, 0);
        for (int i=0, k=0, b='('; i<n; i++) {
            if (s[i] == '1') {
                k++;
                if (k <= (n-c)/2) {
                    p[i] = q[i] = '(';
                } else {
                    p[i] = q[i] = ')';
                }
            } else {
                p[i] = b;
                b = b ^ '(' ^ ')';
                q[i] = b;
            }
        }

        cout << "YES\n";
        cout << p << '\n' << q << '\n';
    }
}