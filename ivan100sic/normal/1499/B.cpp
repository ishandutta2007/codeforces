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
        
        bitset<4> ol;
        ol[0] = 1;
        
        for (char c : s) {
            bitset<4> nu;
            for (int i=0; i<4; i++) {
                if (!ol[i]) continue;
                if (i < 2) {
                    // smes da izbacis
                    nu[i+2] = 1;
                }

                if ((i&1) <= c-'0') {
                    nu[c-'0'] = 1;
                }
            }
            ol = nu;
        }

        cout << (ol.count() ? "YES\n" : "NO\n");
    }
}