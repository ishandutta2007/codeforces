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
        int n;
        string s;
        cin >> n >> s;

        int l = 0;
        while (l < n) {
            auto z = s.find('0', l);
            if ((int)z + 1 < n && s[z+1] == '0') {
                z++;
            }

            if (z == s.npos) {
                for (int i : ra(l, n)) {
                    cout << char('a'-1 + s[i] - '0');
                }
                l = n;
            } else {
                for (int i : ra(l, (int)z-2)) {
                    cout << char('a'-1 + s[i] - '0');
                }
                cout << char('a'-1 + (s[z-2]-'0')*10 + (s[z-1]-'0'));
                l = z+1;
            }
        }
        cout << '\n';
    }
}