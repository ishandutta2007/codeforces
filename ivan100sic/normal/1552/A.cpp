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
        int n, c=0;
        cin >> n;
        string s;
        cin >> s;
        auto p = s;
        sort(begin(p), end(p));
        for (int i=0; i<n; i++) {
            if (p[i] != s[i]) {
                c++;
            }
        }
        cout << c << '\n';
    }
}