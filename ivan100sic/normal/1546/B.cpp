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
        int n, m;
        cin >> n >> m;
        string a(m, 0);
        for (int i=0; i<2*n-1; i++) {
            string s;
            cin >> s;
            for (int j=0; j<m; j++) {
                a[j] ^= s[j];
            }
        }
        cout << a << '\n';
    }
}