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
        string s;
        cin >> s;
        int n = s.size();

        if (s == string(s.size(), '1')) {
            cout << "0\n";
        } else {
            int l = -1, r = -1;
            for (int i=0; i<n; i++) {
                if (s[i] == '0') {
                    if (l == -1) l = i;
                    r = i;
                }
            }

            if (s.substr(l, r-l+1) == string(r-l+1, '0')) {
                cout << "1\n";
            } else {
                cout << "2\n";
            }
        }
    }
}