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
        int n, f=0;
        string s;
        cin >> n >> s;
        for (int i=0; i<n-1; i++) {
            if (s[i] != s[i+1]) {
                cout << i+1 << ' ' << i+2 << '\n';
                f = 1;
                break;
            }
        }

        if (!f) {
            cout << "-1 -1\n";
        }
    }
}