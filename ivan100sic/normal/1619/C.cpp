// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string a0, s, sol = "-1";
        cin >> a0 >> s;

        for (int lz=0; lz<=30; lz++) {
            string a = string(lz, '0') + a0; 
            string b;
            int i = a.size() - 1, j = s.size() - 1;
            while (i >= 0) {
                if (j >= 0 && a[i] <= s[j]) {
                    b = string(1, s[j] - a[i] + '0') + b;
                    j--;
                    i--;
                } else if (j >= 1 && a[i] > s[j] && s[j-1] == '1') {
                    b = string(1, s[j] - a[i] + 10 + '0') + b;
                    j -= 2;
                    i--;
                } else {
                    j = -5;
                    break;
                }
            }

            if (j != -1 || a.size() != b.size()) {
                continue;
            }

            while (b.size() > 1 && b[0] == '0') {
                b.erase(b.begin());
            }

            sol = b;
            break;
        }

        cout << sol << '\n';       
    }
}