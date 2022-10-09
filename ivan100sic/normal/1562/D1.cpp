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
        int n, q;
        string s;
        cin >> n >> q >> s;

        vector<int> z(n+1);
        for (int i=1; i<=n; i++) {
            z[i] = (s[i-1] == '+' ? 1 : -1) - z[i-1];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            int w = z[r] - ((r-l) % 2 ? -1 : 1) * z[l];
            if ((r-l) % 2 == 0) w = -w;

            if (w == 0) {
                cout << "0\n";
            } else {
                cout << ((r-l) % 2 ? 1 : 2) << '\n';
            }
        }
    }
}