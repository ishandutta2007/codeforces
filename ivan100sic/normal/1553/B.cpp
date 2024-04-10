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
        string s, t;
        cin >> s >> t;
        int f = 0;
        for (int i=0; i<(int)s.size(); i++) {
            for (int j=i; j<(int)s.size(); j++) {
                if (j-i >= (int)t.size() || s[j] != t[j-i]) {
                    break;
                }

                // jel moze do kraja?
                int ok = 1;
                for (int k=j-i+1; k<(int)t.size(); k++) {
                    int q = j-1-(k-(j-i+1));
                    if (q < 0 || s[q] != t[k]) {
                        ok = 0;
                        break;
                    }
                }

                if (ok) {
                    f = 1;
                }
            }
        }

        cout << (f ? "YES\n" : "NO\n");
    }
}