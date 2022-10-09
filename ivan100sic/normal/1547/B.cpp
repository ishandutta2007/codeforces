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
        int n = s.size(), l = 0, r = n - 1;
        int ok = 1;
        while (l <= r) {
            if (s[l] == 'a' + (r - l)) {
                l++;
            } else if (s[r] == 'a' + (r - l)) {
                r--;
            } else {
                ok = 0;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}