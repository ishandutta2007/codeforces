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
        for (int i=0; i<n; i++) {
            if (s[i] == 'U') s[i] = 'D';
            else if (s[i] == 'D') s[i] = 'U';
        }

        cout << s << '\n';
    }
}