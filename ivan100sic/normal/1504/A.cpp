// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool pal(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (count(begin(s), end(s), 'a') == (int)s.size()) {
            cout << "NO\n";
        } else {
            string p = s + 'a';
            string q = string(1, 'a') + s;
            cout << "YES\n" << (!pal(p) ? p : q) << '\n';
        }
    }
}